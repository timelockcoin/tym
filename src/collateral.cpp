// Copyright (c) 2020 The TimelockCoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
 
#include <amount.h>
#include <util.h>
#include "chainparams.h"

/**
 * The number of blocks that both new and old MN collateral value will
 * be accepted, for smoother transition.
 */
const unsigned int COLLATERAL_TRANSITION_BLOCKS = 100;

/**
 * Determine the masternode collateral value based on block height
 */
CAmount CollateralRequired(int nHeight)
{
    CAmount nCollateralRequired;
    
    if (nHeight <= 500) {                   // 0 - 500:     Masternodes not enabled
        nCollateralRequired = 0 * COIN;
    } else if (nHeight <= 30000) {
        nCollateralRequired = 200.0001234 * COIN;   // 501 - 30000: 200.0001234 TYM 

    } else if (nHeight <= 195000) {
        nCollateralRequired = 400.0001234 * COIN;

    } else if (nHeight <= 240000) {
        nCollateralRequired = 1000.0001234 * COIN;

    } else if (nHeight <= 280000) {
        nCollateralRequired = 2000.0001234 * COIN;

    } else if (nHeight <= 330000) {
        nCollateralRequired = 3000.0001234 * COIN;

    } else if (nHeight <= 380000) {
        nCollateralRequired = 4000.0001234 * COIN;

    } else if (nHeight <= 420000) {
        nCollateralRequired = 7000.0001234 * COIN;

    } else if (nHeight <= 450000) {
        nCollateralRequired = 8000.0001234 * COIN;

    } else if (nHeight <= 500000) {
        nCollateralRequired = 9000.0001234 * COIN;

    } else if (nHeight <= 550000) {
        nCollateralRequired = 13000.0001234 * COIN;

    } else if (nHeight <= 600000) {
        nCollateralRequired = 15000.0001234 * COIN;

    } else {
        nCollateralRequired = 20000.0001234 * COIN;   // 600001 - max: 20000.0001234 TYM
    }

    return nCollateralRequired;
}


/**
 * Provide transition period for masternode collateral change to avoid
 * unneccessary issues to masternode operators for the amount of 
 * COLLATERAL_TRANSITION_BLOCKS blocks during the collateral change.
 */
bool IsValidCollateral(CAmount nAmountToCheck, int nHeight)
{
    return (
        nAmountToCheck == CollateralRequired(nHeight) || 
        nAmountToCheck == CollateralRequired(nHeight - floor(COLLATERAL_TRANSITION_BLOCKS / 2)) ||
        nAmountToCheck == CollateralRequired(nHeight + floor(COLLATERAL_TRANSITION_BLOCKS / 2))
        );
}

/**
 * Return the number of blocks remaining for collateral to be unlocked
 */
int GetCollateralLockEstimate(int nChainHeight, int nCoinsHeight)
{
    // Lock 200 TYM collaterals until block 30k
    if (nCoinsHeight < 30000) {
        return (nChainHeight < 30000) ? 30000 - nChainHeight : 0;

    } else if (nCoinsHeight <= 195000) {
        return (nChainHeight < 195000) ? 195000 - nChainHeight : 0;

    } else if (nCoinsHeight <= 240000) {
        return (nChainHeight < 240000) ? 240000 - nChainHeight : 0;

    } else if (nCoinsHeight <= 280000) {
        return (nChainHeight < 280000) ? 280000 - nChainHeight : 0;

    } else if (nCoinsHeight <= 330000) {
        return (nChainHeight < 330000) ? 330000 - nChainHeight : 0;

    } else if (nCoinsHeight <= 380000) {
        return (nChainHeight < 380000) ? 380000 - nChainHeight : 0;

    } else if (nCoinsHeight <= 420000) {
        return (nChainHeight < 420000) ? 420000 - nChainHeight : 0;

    } else if (nCoinsHeight <= 450000) {
        return (nChainHeight < 450000) ? 450000 - nChainHeight : 0;

    } else if (nCoinsHeight <= 500000) {
        return (nChainHeight < 500000) ? 500000 - nChainHeight : 0;

    } else if (nCoinsHeight <= 550000) {
        return (nChainHeight < 550000) ? 550000 - nChainHeight : 0;

    } else if (nCoinsHeight <= 600000) {
        return (nChainHeight < 600000) ? 600000 - nChainHeight : 0;

    } else {
        // After the block 600k everything to be locked for 6 months
        int nCollateralMaturityDays = 180;
        int nCollateralMaturityBlocks = (nCollateralMaturityDays * 24 * 3600) / Params().TargetSpacing();
        int nDepth = nChainHeight - nCoinsHeight;

        return (nDepth < nCollateralMaturityBlocks) ? nCollateralMaturityBlocks - nDepth : 0;
    }
}

/**
 * Determine whether the collateral TX is immature to be spent or not
 */
bool IsImmatureCollateral(int nChainHeight, int nCoinsHeight)
{
    return (GetCollateralLockEstimate(nChainHeight, nCoinsHeight) > 0);
}