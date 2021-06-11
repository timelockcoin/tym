// Copyright (c) 2019 The PIVX developers
// Copyright (c) 2020-2021 The TimelockCoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef timelockcoin_PAIRRESULT_H
#define timelockcoin_PAIRRESULT_H


class PairResult {

public:
    PairResult(bool res):result(res){}
    PairResult(bool res, std::string* statusStr):result(res), status(statusStr){}

    bool result;
    std::string* status = nullptr;
};


#endif //timelockcoin_PAIRRESULT_H
