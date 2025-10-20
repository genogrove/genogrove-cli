#include <file_reader_factory.hpp>

static std::unique_ptr<file_reader> create(
    const std::filesystem::path& fpath,
    filetype ftype,
    bool is_gzipped) {
    switch(ftype) {
        case filetype::BED:
            return std::make_unique<bed_reader>(fpath, is_gzipped);
        default:
            return nullptr;
    }
}