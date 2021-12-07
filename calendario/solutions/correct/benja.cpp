#include <iostream>
#include <vector>

using namespace std;

class Calendario {
    public:
        Calendario(int first) : first_(first) {
            week_days_.resize(31);
            used_.resize(31);
            for (int i = 1; i < 31; i++) {
                week_days_[i] = first++ % 7;
                used_[i] = false;
            }
        }

        void do_day_action(int day) {
            last_day = day;
            // Too lazy to do this right
            if (week_days_[day] == 0) {
                lunes(day);
            }
            else if (week_days_[day] == 1) {
                martes(day);
            }
            else if (week_days_[day] == 2) {
                miercoles(day);
            }
            else if (week_days_[day] == 3) {
                jueves(day);
            }
            else if (week_days_[day] == 4) {
                viernes(day);
            }
            else if (week_days_[day] == 5) {
                sabado(day);
            }
            else if (week_days_[day] == 6) {
                domingo(day);
            }
        }

        void lunes(int today) {
            int next = today + 1;
            while (next != today) {
                if (next > 30) {
                    next = 1;
                }
                if (!used_[next]) {
                    used_[next] = true;
                    do_day_action(next);
                    return;
                }
                next++;
            }
            last_day = today;
        } 

        void martes(int day) {
            int next = 31 - day;
            if (used_[next]) {
                last_day = next;
                return;
            }
            used_[next] = true;
            do_day_action(next);
        }

        void miercoles(int day) {
            int next;
            if (day % 2 == 0) {
                next = day - 1;
            }
            else {
                next = day + 1;
            }
            if (used_[next]) {
                last_day = next;
                return;
            }
            used_[next] = true;
            do_day_action(next);
        }

        void jueves(int day) {
            int next = day + 10;
            if (next > 30) {
                next %= 10;
            }
            if (used_[next]) {
                last_day = next;
                return;
            }
            used_[next] = true;
            do_day_action(next);
        }

        void viernes(int day) {
            int next;
            if (day % 2 == 0) {
                next = day / 2;
            }
            else {
                next = 3 * day + 1;
            }
            while (next > 30) {
                next -= 30;
            }
            if (used_[next]) {
                last_day = next;
                return;
            }
            used_[next] = true;
            do_day_action(next);
        }

        void sabado(int day) {
            int next = 2 * day;
            while (next > 30) {
                next -= 30;
            }
            if (used_[next]) {
                last_day = next;
                return;
            }
            used_[next] = true;
            do_day_action(next);
        }

        void domingo(int day) {
            int next = day + 2;
            while (day != next) {
                if (!used_[next]) {
                    used_[next] = true;
                    do_day_action(next);
                    return;
                }
                else {
                    next += 2;
                }
                if (next > 30) {
                    next %= 10;
                }
            }
            last_day = day;
        }

        int last_day;

    private:
        int first_;
        vector<int> week_days_;
        vector<bool> used_;
};

int main () {
    int first, day;
    cin >> first >> day;
    cout << first << day << endl;
    Calendario cal(first);
    cal.do_day_action(day);
    cout << cal.last_day << endl; 
}