# coding: UTF-8

"""
入力：
[ 1年の日数:str
  1カ月の日数:str
  1週間の日数:str
  判別したい日:str
]
"""

"""
メモ
一周するのはremainder daysの総和が１カ月の日数の倍数になるとき
"""


# !/usr/bin/env python3


class make_calender:
    def __init__(self, year_days, month_days, week_days):
        self.year_days = year_days
        self.month_days = month_days
        self.week_days = week_days
        self.remain_days = year_days % month_days

    # 年における月数のサイクルを求める
    def get_cycle_month(self):
        year_month = []
        remain = self.remain_days
        while True:
            year_month.append(int(self.year_days / self.month_days))
            if remain >= self.month_days:
                year_month[-1] += 1
                remain -= self.month_days
            if remain == 0:
                break
            remain += self.remain_days
        return year_month

    # 指定された日が正しいかのチェック
    def check_input(self, input_month, input_day):
        cycle = self.get_cycle_month()
        if input_day > self.month_days or input_month > cycle[input_month % len(cycle)]:
            return False
        else:
            return True

    # チェックの年に対応する日数を求める
    def get_days_of_year(self, check_year):
        cycle = self.get_cycle_month()
        cycle_days = 0
        for month in cycle:
            cycle_days += month * self.month_days
        remain_days = 0
        if check_year % len(cycle) != 0:
            for i in range(0, (check_year % len(cycle))):
                remain_days += self.month_days * cycle[i]
        return int(check_year / len(cycle))*cycle_days + remain_days

    # チェックの月に対応する日数を求める
    def get_days_of_month(self, check_month):
        return (check_month) * self.month_days

    # チェックの日の曜日を求める
    def get_day_of_the_week(self, check_year, check_month, check_day):
        number_of_day_of_the_weekend = (self.get_days_of_year(check_year) + self.get_days_of_month(check_month) + check_day) % self.week_days
        if number_of_day_of_the_weekend == 0:
            return chr(64 + self.week_days)
        else:
            return chr(64 + number_of_day_of_the_weekend)



def main(argv):

    a_year_days = int(argv[0])
    a_month_days = int(argv[1])
    a_week_days = int(argv[2])
    check = argv[3]
    # a_year_days = 160
    # a_month_days = 30
    # a_week_days = 7
    # check = "00001-01-30"
    # check = "00003-01-01"
    check_list = check.split("-")
    check_year = int(check_list[0]) - 1
    check_month = int(check_list[1]) - 1
    check_day = int(check_list[2])

    check = make_calender(a_year_days, a_month_days, a_week_days)
    # print("days of year : " + str(check.get_days_of_year(check_year)))
    # print("days of month : " + str(check.get_days_of_month(check_month)))

    if check.check_input(check_month, check_day):
        print(check.get_day_of_the_week(check_year, check_month, check_day))
    else:
        print(-1)

# main()