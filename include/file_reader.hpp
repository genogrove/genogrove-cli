/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Richard A. Schäfer
 *
 * This file is part of genogrove and is licensed under the terms of the MIT license.
 * See the LICENSE file in the root of the repository for more information.
 */

#ifndef GENOGROVE_CLI_FILEREADER_HPP
#define GENOGROVE_CLI_FILEREADER_HPP

// genogrove
// #include <genogrove/data_type/interval.hpp>

class file_reader {
    public:
        virtual bool read_next(FileEntry& entry) = 0;
        virtual bool hasNext() = 0;
        virtual std::string getErrorMessage() = 0;
        virtual size_t getCurrentLine() = 0;
        virtual ~FileReader() = default;
};


#endif //GENOGROVE_CLI_FILEREADER_HPP