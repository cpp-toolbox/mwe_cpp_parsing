#include "utility/cpp_parsing/cpp_parsing.hpp"

int main() {

    cpp_parsing::test();

    auto class_str = "class X { public: int val = 1; bool thing = false; bool thing2; };";

    // cpp_parsing::test_parser(class_str, cpp_parsing::class_def_parser_good);
    auto pr = cpp_parsing::class_def_parser_good->parse(class_str, 0);
    auto parser_name_to_matches = cpp_parsing::collect_matches_by_parser_name(pr);

    // std::cout << "gooblas" << std::endl;
    // std::cout << pr.to_string() << std::endl;

    // I don't think ti works because something about the recurssion stopping
    for (const auto &parser_name : {cpp_parsing::assignment_parser->name, cpp_parsing::declaration_parser->name}) {
        std::cout << parser_name << std::endl;
        for (const auto &match : parser_name_to_matches[parser_name]) {
            std::cout << match << std::endl;
        }
    }

    if (false) {
        auto s = "basic_math.cpp";

        // auto tlfs = cpp_parsing::extract_top_level_functions(s);
        //
        // for (const auto &tlf : tlfs) {
        //     std::cout << "=== FUNCTION START ===" << std::endl;
        //     std::cout << tlf << std::endl;
        //     std::cout << "=== FUNCTION END ===" << std::endl;
        // }

        auto pntm = cpp_parsing::get_parser_name_to_matches_for_source_file(s);

        for (const auto &[parser_name, matches] : pntm) {
            std::cout << "=== PARSER " << parser_name << " START ===" << std::endl;
            int i = 0;
            for (const auto &m : matches) {
                std::cout << i << " : " << m << std::endl;
                i++;
            }
            std::cout << "=== PARSER " << parser_name << " end ===" << std::endl;
        }
    }

    return 0;
}
