#include "filetype_detector.hpp"


#include <subcall/index.hpp>

cxxopts::Options subcall::parse_args(int argc, char** argv) {
    cxxopts::Options options("genogrove index", "index an interval file");
    options.add_options()
            ("inputfile", "The input file to be indexed",
                    cxxopts::value<std::string>())
            ("o, outputfile", "Write the index to the specified file",
                    cxxopts::value<std::string>())
            ("k, order", "The order of the tree",
                    cxxopts::value<int>()->default_value("3"))
            ("s, sorted", "Interval in the input file are sorted",
                    cxxopts::value<bool>()->default_value("false"))
            ("t, timed", "Measure the time taken for indexing",
                    cxxopts::value<bool>()->default_value("false"))
            ("h, help", "Print help")
            ;
    options.parse_positional({"inputfile"});
    options.positional_help("inputfile");

    return options;
}

void index::validate(const cxxopts::ParseResult& args) {
    if(args.count("inputfile")) {
        std::string inputfile = args["inputfile"].as<std::string>();
        // check if the file exists
        if(!std::filesystem::exists(inputfile)) {
            std::cerr << "File does not exist: " << inputfile << "\n";
            exit(1);
        }
    }
}

void index::execute(const cxxopts::ParseResult& args) {
    auto start_program = std::chrono::steady_clock::now();
    std::filesystem::path inputfile = args["inputfile"].as<std::string>();
    std::cout << "Indexing file: " << inputfile << "\n";

    // detect the file type
    auto [filetype, is_gzipped] = filetype_detector().detect_filetype(inputfile);
    std::unique_ptr<file_reader> reader = file_reader_factory::create(inputfile, filetype, is_gzipped);

    // create the grove






}