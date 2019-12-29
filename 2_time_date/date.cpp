// Boost date_time is not a header-only library.
// CMakelists.txt: find_package(Boost REQUIRED COMPONENTS date_time)

#define DATE_TIME_NO_DEFAILT_CONSTRUCTOR

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>

using namespace boost::gregorian;
using namespace boost::posix_time;
using namespace std;

int main(int argc, char* argv[]) {
    // define a date
    date d1;
    date d2(2010, 1, 1);
    date d3(2000, Jan, 1);
    date d4(d2);

    // checke date. The code will be crashed if fail.
    assert(d1 == date(not_a_date_time));
    assert(d2 == d4);
    assert(d3 < d4);
    cout << "d3 < d4" << endl;

    // define a date from string
    date d5 = from_string("1992-12-31");
    date d6(from_string("1995/1/1"));
    date d7 = from_undelimited_string("20011118");

    // border
    date d8(neg_infin);
    date d9(pos_infin);
    date d10(not_a_date_time);
    date d11(max_date_time);
    date d12(min_date_time);
    cout << d8 << endl;
    cout << d9 << endl;
    cout << d10 << endl;
    cout << d11 << endl;
    cout << d12 << endl;

    // date d_error(19999, 1, 1);  // wrong constructor that exceeds the border

    // access the date
    date d13(2014, 4, 1);
    assert(d13.year() == 2014);
    assert(d13.month() == 4);
    assert(d13.day() == 1);

    cout << d13.day_of_week() << endl;
    cout << d13.day_of_year() << endl;
    assert(d13.end_of_month() == date(2014, 4, 30));
    assert((!d13.is_special()) || d13.is_infinity() || d13.is_not_a_date() || d13.is_neg_infinity() ||
           d13.is_pos_infinity());

    // output the date
    cout << to_simple_string(d13) << endl;        // 2014-Apr-01
    cout << to_iso_string(d13) << endl;           // 20140401
    cout << to_iso_extended_string(d13) << endl;  // 2014-04-01

    // convert from/to C tm struct
    date d14(2014, 2, 1);
    tm t = to_tm(d14);
    assert(t.tm_hour == 0 && t.tm_min == 0);     // int tm_year;    /* Year - 1900.  */
    assert(t.tm_year == 114 && t.tm_mday == 1);  // int tm_mday;    /* Day.   [1-31] */

    date d15 = date_from_tm(t);
    assert(d14 == d15);

    // date duration
    weeks w1(3);
    assert(w1.days() == 21);

    months m1(3);
    years y1(1);
    months m2 = y1 + m1;
    assert(m2.number_of_months() == 15);

    // date calculation
    date d16(2009, 1, 1);
    date d17(2009, 1, 31);
    cout << d17 - d16 << endl;

    // date period
    date_period dp1(date(2014, 1, 1), days(30));   // valid, [20140101,20140131)
    date_period dp2(date(2014, 1, 1), days(-30));  // invalid, but no exception thrown out, and is_null returns true
    date_period dp3(date(2014, 1, 1), date(2014, 1, 31));  // valid, [20140101,20140131)
    date_period dp4(date(2014, 1, 1),
                    date(2013, 1, 31));  // invalid, but no exception thrown out, and is_null returns true

    assert(!dp1.is_null());
    assert(dp2.is_null());
    assert(dp1 == dp3);
    assert(dp1.begin().day() == 1);
    assert(dp1.last().day() == 30);
    assert(dp1.end().day() == 31);
    assert(dp1.length().days() == 30);

    date_period dp5(date(2014, 3, 1), days(31));
    cout << dp5 << endl;
    assert(dp1 < dp5);

    // date period calculation
    assert(dp5.is_after(date(2008, 1, 1)));  // comparison object is a date but not a date period
    assert(dp5.contains(date(2014, 3, 13)));

    date_period dp6(date(2014, 2, 24), days(39));
    assert(dp5.intersects(dp6));  // object is a date period
    assert(!dp5.intersection(dp6).is_null());
    assert(!dp5.is_adjacent(dp6));

    // date iterator
    date d18(2006, 11, 26);
    day_iterator d_iter(d18);  // default step length is 1 day

    assert(d_iter == d18);
    ++d_iter;
    assert(d_iter == date(2006, 11, 27));

    year_iterator y_iter(*d_iter, 8);  // default step length is 8 years
    assert(y_iter == d18 + days(1));
    ++y_iter;
    assert(y_iter->year() == 2014);

    return 1;
}
