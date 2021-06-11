// Copyright (c) 2020 The TimelockCoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
 
#include <util.h>

/**
 * Determine the masternode collateral value based on block height
 */
CAmount CollateralRequired(int nHeight);

/**
 * Provide transition period for masternode collateral change to avoid
 * unneccessary issues to masternode operators, returns true if given
 * amount is accepted as valid collateral.
 */
bool IsValidCollateral(CAmount nAmountToCheck, int nHeight);

/**
 * Return the number of blocks remaining for collateral to be unlocked
 */
int GetCollateralLockEstimate(int nChainHeight, int nCoinsHeight);

/**
 * Determine whether the collateral TX is immature to be spent or not
 */
bool IsImmatureCollateral(int nChainHeight, int nCoinsHeight);