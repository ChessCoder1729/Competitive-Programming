// anticlockwise is positive
struct point{
    int x,y;
    
    point operator -(const point &p) const{
        return point({x-p.x,y-p.y});
    }
    point operator +(const point &p) const{
        return point({x+p.x,y+p.y});
    }
    int cross_product(const point &p) const{
        // Cross Product = 2*Area
        // The angle from a to b
        // Since anticlockwise is postive:
        // Cross prod > 0 => Angle is anticlockwise => b is to the left of a
        return x*p.y - p.x*y;
    }
};