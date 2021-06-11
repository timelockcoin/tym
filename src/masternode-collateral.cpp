// Copyright (c) 2020 The TimelockCoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
 
#include <amount.h>
#include <util.h>
#include <chainparams.h>

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
    
    if (nHeight <= 1000) {                   // 0 - 1000:     Masternodes not enabled
        nCollateralRequired = 0;

    } else if (nHeight <= 10000) {
        nCollateralRequired = 2.0001234 * COIN;   // 1000 - 10000: 2.0001234 TYM 

    } else if (nHeight <= 15000) {
        nCollateralRequired = 10.0001234 * COIN;

    } else if (nHeight <= 20000) {
        nCollateralRequired = 25.0001234 * COIN;

    } else if (nHeight <= 25000) {
        nCollateralRequired = 50.0001234 * COIN;

    } else if (nHeight <= 30000) {
        nCollateralRequired = 100.0001234 * COIN;

    } else if (nHeight <= 35000) {
        nCollateralRequired = 300.0001234 * COIN;

    } else if (nHeight <= 40000) {
        nCollateralRequired = 800.0001234 * COIN;

    } else {
        nCollateralRequired = 5000.0001234 * COIN;   // 40001 - max: 5000.0001234 TYM
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
    if (nCoinsHeight < 10000) {
        return (nChainHeight < 10000) ? 10000 - nChainHeight : 0;

    } else if (nCoinsHeight <= 15000) {
        return (nChainHeight < 15000) ? 15000 - nChainHeight : 0;

    } else if (nCoinsHeight <= 20000) {
        return (nChainHeight < 20000) ? 20000 - nChainHeight : 0;

    } else if (nCoinsHeight <= 25000) {
        return (nChainHeight < 25000) ? 25000 - nChainHeight : 0;

    } else if (nCoinsHeight <= 30000) {
        return (nChainHeight < 30000) ? 30000 - nChainHeight : 0;

    } else if (nCoinsHeight <= 35000) {
        return (nChainHeight < 35000) ? 35000 - nChainHeight : 0;

    } else if (nCoinsHeight <= 40000) {
        return (nChainHeight < 40000) ? 40000 - nChainHeight : 0;

    } else {
        // After the block 600k everything to be locked for 6 months
        int nCollateralMaturityDays = 180;
        int nCollateralMaturityBlocks = (nCollateralMaturityDays * 24 * 3600) / Params().GetConsensus().nTargetSpacing;
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