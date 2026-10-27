#include <gtest/gtest.h>

#include <string>

std::string convert_mark_into_word_22(int mark) {
    std::string res;
    switch (mark) {
        case 2:
            res = "двойка";
            break;
        case 3:
            res = "тройка";
            break;
        case 4:
            res = "четверка";
            break;
        case 5:
            res = "пятерка";
            break;
    }
    return res;
}

std::string convert_ones_to_string(int number) {
    switch (number) {
        case 1:
            return "один";
        case 2:
            return "два";
        case 3:
            return "три";
        case 4:
            return "четыре";
        case 5:
            return "пять";
        case 6:
            return "шесть";
        case 7:
            return "семь";
        case 8:
            return "восемь";
        case 9:
            return "девять";
        default:
            return "";
    }
}

std::string convert_tens_to_string(int number) {
    switch (number) {
        case 2:
            return "двадцать";
        case 3:
            return "тридцать";
        case 4:
            return "сорок";
        case 5:
            return "пятьдесят";
        case 6:
            return "шестьдесят";
        case 7:
            return "семьдесят";
        case 8:
            return "восемьдесят";
        case 9:
            return "девяносто";
        default:
            return "";
    }
}

std::string get_years_by_number(int number) {
    switch (number) {
        case 1:
            return "год";
        case 2:
        case 3:
        case 4:
            return "года";
        default:
            return "лет";
    }
}

std::string convert_year_to_text_56(int year) {
    if (year < 20 || year > 69) {
        return "";
    }
    std::string res;
    int last_number = year % 10;
    int first_number = year / 10;
    auto tens = convert_tens_to_string(first_number);
    if (tens != "") {
        res += tens + " ";
    }
    auto ones = convert_ones_to_string(last_number);
    if (ones != "") {
        res += ones + " ";
    }
    return res + get_years_by_number(last_number);
}

namespace case_tasks {
TEST(Test22, TestWith2) {
    int mark = 2;
    auto res = convert_mark_into_word_22(mark);
    EXPECT_EQ(res, "двойка");
}
TEST(Test22, TestWith3) {
    int mark = 3;
    auto res = convert_mark_into_word_22(mark);
    EXPECT_EQ(res, "тройка");
}
TEST(Test22, TestWith4) {
    int mark = 4;
    auto res = convert_mark_into_word_22(mark);
    EXPECT_EQ(res, "четверка");
}
TEST(Test22, TestWith5) {
    int mark = 5;
    auto res = convert_mark_into_word_22(mark);
    EXPECT_EQ(res, "пятерка");
}
TEST(Test22, TestWithNotMatching) {
    int mark = 123;
    auto res = convert_mark_into_word_22(mark);
    EXPECT_EQ(res, "");
}
TEST(Test56, TestFor20) {
    int year = 20;
    auto res = convert_year_to_text_56(year);
    EXPECT_EQ(res, "двадцать лет");
}

TEST(Test56, TestFor42) {
    int year = 42;
    auto res = convert_year_to_text_56(year);
    EXPECT_EQ(res, "сорок два года");
}

TEST(Test56, TestFor51) {
    int year = 51;
    auto res = convert_year_to_text_56(year);
    EXPECT_EQ(res, "пятьдесят один год");
}
TEST(Test56, TestNotPassingNumber) {
    int year = 1;
    auto res = convert_year_to_text_56(year);
    EXPECT_EQ(res, "");
}

}  // namespace case_tasks
