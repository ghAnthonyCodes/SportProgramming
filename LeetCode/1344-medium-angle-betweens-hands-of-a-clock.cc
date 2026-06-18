class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour == 12) hour = 0;
        double HOUR_ANGLE_OFFSET = 30;
        double HOUR_MIN_HAND_ADDITIONAL = 0.5;
        double MIN_HAND_RESOLUTION = 6;
        double minute_angle = minutes * MIN_HAND_RESOLUTION;
        double hour_angle = hour * HOUR_ANGLE_OFFSET + minutes * HOUR_MIN_HAND_ADDITIONAL;
        double option_a = hour_angle - minute_angle;
        double option_b = minute_angle - hour_angle;
        if (option_a < 0) option_a += 360;
        if (option_b < 0) option_b += 360;
        return min(option_a, option_b);
    }
};
