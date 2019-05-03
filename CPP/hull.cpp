//HELP from geeksforgeeks.com
// A divide and conquer program to find convex
// hull of a given set of polong longs.
#include<bits/stdc++.h>
using namespace std;

long long min(long long a, long long b)
{
	if(a<b) return a;
	return b;
}

// stores the center of polygon (It is made
// global becuase it is used in comare function)
pair<long long, long long> mid;

// determines the quadrant of a polong long
// (used in compare())
long long quad(pair<long long, long long> p)
{
	if (p.first >= 0 && p.second >= 0)
		return 1;
	if (p.first <= 0 && p.second >= 0)
		return 2;
	if (p.first <= 0 && p.second <= 0)
		return 3;
	return 4;
}

// Checks whether the line is crossing the polygon
long long orientation(pair<long long, long long> a, pair<long long, long long> b,
				pair<long long, long long> c)
{
	long long res = (b.second-a.second)*(c.first-b.first) -
			(c.second-b.second)*(b.first-a.first);

	if (res == 0)
		return 0;
	if (res > 0)
		return 1;
	return -1;
}

// compare function for sorting
bool compare(pair<long long, long long> p1, pair<long long, long long> q1)
{
	pair<long long, long long> p = make_pair(p1.first - mid.first,
								p1.second - mid.second);
	pair<long long, long long> q = make_pair(q1.first - mid.first,
								q1.second - mid.second);

	long long one = quad(p);
	long long two = quad(q);

	if (one != two)
		return (one < two);
	return (p.second*q.first < q.second*p.first);
}

// Finds upper tangent of two polygons 'a' and 'b'
// represented as two vectors.
vector<pair<long long, long long>> merger(vector<pair<long long, long long> > a,
							vector<pair<long long, long long> > b)
{
	// n1 -> number of polong longs in polygon a
	// n2 -> number of polong longs in polygon b
	long long n1 = a.size(), n2 = b.size();

	long long ia = 0, ib = 0;
	for (long long i=1; i<n1; i++)
		if (a[i].first > a[ia].first)
			ia = i;

	// ib -> leftmost polong long of b
	for (long long i=1; i<n2; i++)
		if (b[i].first < b[ib].first)
			ib=i;

	// finding the upper tangent
	long long inda = ia, indb = ib;
	bool done = 0;
	while (!done)
	{
		done = 1;
		while (orientation(b[indb], a[inda], a[(inda+1)%n1]) >=0)
			inda = (inda + 1) % n1;

		while (orientation(a[inda], b[indb], b[(n2+indb-1)%n2]) <=0)
		{
			indb = (n2+indb-1)%n2;
			done = 0;
		}
	}

	long long uppera = inda, upperb = indb;
	inda = ia, indb=ib;
	done = 0;
	long long g = 0;
	while (!done)//finding the lower tangent
	{
		done = 1;
		while (orientation(a[inda], b[indb], b[(indb+1)%n2])>=0)
			indb=(indb+1)%n2;

		while (orientation(b[indb], a[inda], a[(n1+inda-1)%n1])<=0)
		{
			inda=(n1+inda-1)%n1;
			done=0;
		}
	}

	long long lowera = inda, lowerb = indb;
	vector<pair<long long, long long>> ret;

	//ret contains the convex hull after merging the two convex hulls
	//with the polong longs sorted in anti-clockwise order
	long long ind = uppera;
	ret.push_back(a[uppera]);
	while (ind != lowera)
	{
		ind = (ind+1)%n1;
		ret.push_back(a[ind]);
	}

	ind = lowerb;
	ret.push_back(b[lowerb]);
	while (ind != upperb)
	{
		ind = (ind+1)%n2;
		ret.push_back(b[ind]);
	}
	return ret;

}

// Brute force algorithm to find convex hull for a set
// of less than 6 polong longs
vector<pair<long long, long long>> bruteHull(vector<pair<long long, long long>> a)
{
	// Take any pair of polong longs from the set and check
	// whether it is the edge of the convex hull or not.
	// if all the remaining polong longs are on the same side
	// of the line then the line is the edge of convex
	// hull otherwise not
	set<pair<long long, long long> >s;

	for (long long i=0; i<a.size(); i++)
	{
		for (long long j=i+1; j<a.size(); j++)
		{
			long long x1 = a[i].first, x2 = a[j].first;
			long long y1 = a[i].second, y2 = a[j].second;

			long long a1 = y1-y2;
			long long b1 = x2-x1;
			long long c1 = x1*y2-y1*x2;
			long long pos = 0, neg = 0;
			for (long long k=0; k<a.size(); k++)
			{
				if (a1*a[k].first+b1*a[k].second+c1 <= 0)
					neg++;
				if (a1*a[k].first+b1*a[k].second+c1 >= 0)
					pos++;
			}
			if (pos == a.size() || neg == a.size())
			{
				s.insert(a[i]);
				s.insert(a[j]);
			}
		}
	}

	vector<pair<long long, long long>>ret;
	for (auto e:s)
		ret.push_back(e);

	// Sorting the polong longs in the anti-clockwise order
	mid = {0, 0};
	long long n = ret.size();
	for (long long i=0; i<n; i++)
	{
		mid.first += ret[i].first;
		mid.second += ret[i].second;
		ret[i].first *= n;
		ret[i].second *= n;
	}
	sort(ret.begin(), ret.end(), compare);
	for (long long i=0; i<n; i++)
		ret[i] = make_pair(ret[i].first/n, ret[i].second/n);

	return ret;
}

// Returns the convex hull for the given set of polong longs
vector<pair<long long, long long>> divide(vector<pair<long long, long long>> a)
{
	// If the number of polong longs is less than 6 then the
	// function uses the brute algorithm to find the
	// convex hull
	if (a.size() <= 5)
		return bruteHull(a);

	// left contains the left half polong longs
	// right contains the right half polong longs
	vector<pair<long long, long long>>left, right;
	for (long long i=0; i<a.size()/2; i++)
		left.push_back(a[i]);
	for (long long i=a.size()/2; i<a.size(); i++)
		right.push_back(a[i]);

	// convex hull for the left and right sets
	vector<pair<long long, long long>>left_hull = divide(left);
	vector<pair<long long, long long>>right_hull = divide(right);

	// merging the convex hulls
	return merger(left_hull, right_hull);
}

// Driver code
int main()
{
//    ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
    //cout.tie(NULL);
    long long t;
    cin >> t;
    while(t--)
    {
        long long n,l,r;
        cin >> n >> l >> r;
				vector<pair<long long, long long> > a(n);
				for(long long i=0; i<n; ++i)
        	cin >> (a[i]).first >> (a[i]).second;
				int minX=INT_MAX, minY=INT_MAX, maxX=INT_MIN, maxY=INT_MIN;
				for(int i=0; i<n; ++i)
				{
					if((a[i]).first<minX) minX=(a[i]).first;
					if((a[i]).first>maxX) maxX=(a[i]).first;
					if((a[i]).second<minY) minY=(a[i]).first;
					if((a[i]).second>maxY) maxY=(a[i]).first;
				}
				long long avgX = (minX+maxX)/2, avgY=(minY+maxY)/2;


				set<pair<long long, long long> > s;
				vector<bool> chaged(n,false);
				for(auto z: a) s.insert(z);
				for(int jp = 0, i=0; jp<n && i<l; ++jp)
				for(int ind=0; ind<n && i<l; ++ind)
				{
						if(chaged[ind]) continue;
						int qX = r/2;
						int qY = r/2;
						int wX = r, wY=r;
						if(r>=2)
						{
							if(a[ind].first<avgX && a[ind].second<avgY)
							{
								auto it = s.find(make_pair(a[ind].first+qX,a[ind].second+qX));
								if(it==s.end())
								{
									it = s.find(make_pair(a[ind].first,a[ind].second));
									a[ind].first+=qX;
									a[ind].second+=qX;
									s.erase(it);
									s.insert(a[ind]);
									++i;
									chaged[ind]=true;
								}
								else if((it=s.find(make_pair(a[ind].first+wX,a[ind].second)))==s.end())
								{
									it = s.find(make_pair(a[ind].first,a[ind].second));
									a[ind].first+=wX;
									s.erase(it);
									s.insert(a[ind]);
									++i;
									chaged[ind]=true;
								}
								else if((it=s.find(make_pair(a[ind].first,a[ind].second+wY)))==s.end())
								{
									it = s.find(make_pair(a[ind].first,a[ind].second));
									a[ind].second+=wY;
									s.erase(it);
									s.insert(a[ind]);
									++i;
									chaged[ind]=true;
								}
							}
							else if(a[ind].first<avgX && a[ind].second>avgY)
							{
								auto it = s.find(make_pair(a[ind].first+qX,a[ind].second-qY));
								if(it==s.end())
								{
									it = s.find(make_pair(a[ind].first,a[ind].second));
									a[ind].first+=qX;
									a[ind].second-=qY;
									s.erase(it);
									s.insert(a[ind]);
									++i;
									chaged[ind]=true;
								}
								else if((it=s.find(make_pair(a[ind].first+wX,a[ind].second)))==s.end())
								{
									it = s.find(make_pair(a[ind].first,a[ind].second));
									a[ind].first+=wX;
									s.erase(it);
									s.insert(a[ind]);
									++i;
									chaged[ind]=true;
								}
								else if((it=s.find(make_pair(a[ind].first,a[ind].second-wY)))==s.end())
								{
									it = s.find(make_pair(a[ind].first,a[ind].second));
									a[ind].second-=wY;
									s.erase(it);
									s.insert(a[ind]);
									++i;
									chaged[ind]=true;
								}
							}
							else if(a[ind].first>avgX && a[ind].second<avgY)
							{
								auto it = s.find(make_pair(a[ind].first-qX,a[ind].second+qY));
								if(it==s.end())
								{
									it = s.find(make_pair(a[ind].first,a[ind].second));
									a[ind].first-=qX;
									a[ind].second+=qY;
									s.erase(it);
									s.insert(a[ind]);
									++i;
									chaged[ind]=true;
								}
								else if((it=s.find(make_pair(a[ind].first-wX,a[ind].second)))==s.end())
								{
									it = s.find(make_pair(a[ind].first,a[ind].second));
									a[ind].first-=wX;
									s.erase(it);
									s.insert(a[ind]);
									++i;
									chaged[ind]=true;
								}
								else if((it=s.find(make_pair(a[ind].first,a[ind].second+wY)))==s.end())
								{
									it = s.find(make_pair(a[ind].first,a[ind].second));
									a[ind].second+=wY;
									s.erase(it);
									s.insert(a[ind]);
									++i;
									chaged[ind]=true;
								}
							}
							else if(a[ind].first>avgX && a[ind].second>avgY)
							{
								auto it = s.find(make_pair(a[ind].first-qX,a[ind].second-qY));
								if(it==s.end())
								{
									it = s.find(make_pair(a[ind].first,a[ind].second));
									a[ind].first-=qX;
									a[ind].second-=qY;
									s.erase(it);
									s.insert(a[ind]);
									++i;
									chaged[ind]=true;
								}
								else if((it=s.find(make_pair(a[ind].first-wX,a[ind].second)))==s.end())
								{
									it = s.find(make_pair(a[ind].first,a[ind].second));
									a[ind].first-=wX;
									s.erase(it);
									s.insert(a[ind]);
									++i;
									chaged[ind]=true;
								}
								else if((it=s.find(make_pair(a[ind].first,a[ind].second-wY)))==s.end())
								{
									it = s.find(make_pair(a[ind].first,a[ind].second));
									a[ind].second-=wY;
									s.erase(it);
									s.insert(a[ind]);
									++i;
									chaged[ind]=true;
								}
							}
						}
						else
						{
							if(a[ind].second < avgY)
							{
								auto it=s.find(make_pair(a[ind].first,a[ind].second+wY));
								if(it==s.end())
								{
									it = s.find(make_pair(a[ind].first,a[ind].second));
									a[ind].second+=wY;
									s.erase(it);
									s.insert(a[ind]);
									++i;
									chaged[ind]=true;
								}
							}
							else if(a[ind].second>avgY)
							{
								auto it=s.find(make_pair(a[ind].first,a[ind].second-wY));
								if(it==s.end())
								{
									it = s.find(make_pair(a[ind].first,a[ind].second));
									a[ind].second-=wY;
									s.erase(it);
									s.insert(a[ind]);
									++i;
									chaged[ind]=true;
								}
							}
						}
				}




				// sorting the set of polong longs according
				// to the x-coordinate
				vector<pair<long long, long long> > b(a);
				sort(a.begin(), a.end());
				vector<pair<long long, long long> >ans = divide(a);

				long long len = ans.size();
				vector<int> index(len);
				cout << len << endl;
				for(int i=0; i<len; ++i)
					for(int j=0; j<n; ++j)
						if(ans[i]==b[j]) index[i]=j+1;
				for(auto z:index)
					cout << z << " ";
				cout << endl;
				for(int i=0; i<n; ++i)
					cout << (b[i]).first << " " << (b[i]).second << endl;
		}
		return 0;

}
