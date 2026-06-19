class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans;
        double x,y;
      x = (hour % 12) * 5.0 + (minutes / 60.0) * 5.0;
        y=double(minutes);
        ans=abs(x-y)<(60-abs(x-y))?abs(x-y)*6:(60-abs(x-y))*6;

        return ans;

    }
};