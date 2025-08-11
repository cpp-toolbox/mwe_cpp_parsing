#include "utility/cpp_parsing/cpp_parsing.hpp"

int main() {

    cpp_parsing::test();

    if (true) {
        auto s = "vertex_geometry.cpp";

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
