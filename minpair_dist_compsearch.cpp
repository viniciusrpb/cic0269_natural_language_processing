#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll oo = 1e18;

typedef struct point Point2D;

struct point
{
    int x;
    int y;
    
    bool operator<(Point2D p)
    {
        return x < p.x || (x == p.x && y < p.y);
    }
};

double dist(Point2D a, Point2D b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

bool sortX(Point2D a, Point2D b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool sortY(Point2D a, Point2D b)
{
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

double min_dist(Point2D parte[], int n, double d)
{
    double ans = d;
    
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n && (parte[j].y - parte[i].y) < ans; j++)
            if (dist(parte[i],parte[j]) < ans)
                ans = dist(parte[i], parte[j]);
 
    return ans;
}


double mindist_pair_points_n2(vector<Point2D> points, int n)
{
    double d = oo;
    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            d = min(d,dist(points[i],points[j]));
        }
    }
    
    return d;
}

double mindist_pair_points_n22(Point2D points[], int n)
{
    double d = oo;
    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            d = min(d,dist(points[i],points[j]));
        }
    }
    
    return d;
}

double mindist_pair_points(Point2D points_x[], Point2D points_y[], int n)
{
    
    if (n <= 3)
        return mindist_pair_points_n22(points_x, n);
    
    int mid = n/2;
 
    Point2D parte_esq[mid];
    Point2D parte_dir[n-mid];
    
    int l = 0;
    int r = 0;
    
    for (int i = 0; i < n; i++)
    {
      if ((points_y[i].x < points_x[mid].x || (points_y[i].x == points_x[mid].x && points_y[i].y < points_x[mid].y)) && l<mid)
         parte_esq[l++] = points_y[i];
      else
         parte_dir[r++] = points_y[i];
    }
 
    double dE = mindist_pair_points(points_x, parte_esq, mid);
    double dR = mindist_pair_points(points_x, parte_dir, n-mid);
 
    double d = min(dE, dR);
 
    Point2D strip[n];
    
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(points_y[i].x - points_x[mid].x) < d)
            strip[j++] = points_y[i];
 
    return min_dist(strip, j, d);
}

float mindist_pair_points_nlogn(vector<Point2D> points, int n)
{
    Point2D p_ord_x[n];
    Point2D p_ord_y[n];
    
    sort(points.begin(),points.end(),sortX);
    
    for (int i = 0; i < n; i++)
        p_ord_x[i] = points[i];
    
    sort(points.begin(),points.end(),sortY);
    
    for (int i = 0; i < n; i++)
        p_ord_y[i] = points[i];
    
    return mindist_pair_points(p_ord_x, p_ord_y, n);
}

double closest_pair(vector<Point2D> points)
{
    int n = points.size();
    sort(points.begin(), points.end());
    set<pii> s;

    ll best_sd = 1e18;
    int j = 0;
    
    for (int i = 0; i < n; ++i)
    {
        int d = ceil(sqrt(best_sd));
        
        // se d mudou, temos que atualizar os pontos que fazem parte do set
        while (j < n && points[i].x - points[j].x >= d){
            s.erase({points[j].y, points[j].x});
            j++;
        }

        auto it1 = s.lower_bound({points[i].y - d, points[i].x});
        auto it2 = s.upper_bound({points[i].y + d, points[i].x});
        
        for (auto it = it1; it != it2; ++it) {
            ll dx = points[i].x - it->second;
            ll dy = points[i].y - it->first;
            best_sd = min(best_sd, dx * dx + dy * dy);      
        } 
        s.insert({points[i].y, points[i].x});
    }
    return sqrt(best_sd);
}



int main()
{
    
    vector<Point2D> point_cloud;
    
    /*point_cloud.push_back({2, 3});
    point_cloud.push_back({12, 30});
    point_cloud.push_back({40, 50});
    point_cloud.push_back({5, 1});
    point_cloud.push_back({12, 10});
    point_cloud.push_back({3, 4});*/
    
    point_cloud.push_back({-2, -1});
    point_cloud.push_back({0, 3});
    point_cloud.push_back({1, -2});
    point_cloud.push_back({3, 4});
    point_cloud.push_back({4, 2});

    cout << "The smallest distance is " << mindist_pair_points_n2(point_cloud,5) << "\n";
    cout << "The smallest distance is " << mindist_pair_points_nlogn(point_cloud, 5) << "\n";
    cout << "The smallest distance is " << closest_pair(point_cloud) << "\n";
    
    return 0;
}




