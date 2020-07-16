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
        nCollateralRequired = 200.0001234 * COIN;   // 501 - 30000: 300.0001234 TYM 
    } else {
        nCollateralRequired = 400.0001234 * COIN;   // 30001 - max: 400.0001234 TYM
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
    }

    // Collaterals of 400 TYM (after bock 30k) to be locked for 180 days
    int nCollateralMaturityDays = 180;
    int nCollateralMaturityBlocks = (nCollateralMaturityDays * 24 * 3600) / Params().TargetSpacing();
    int nDepth = nChainHeight - nCoinsHeight;

    return (nDepth < nCollateralMaturityBlocks) ? nCollateralMaturityBlocks - nDepth : 0;
}

/**
 * Determine whether the collateral TX is immature to be spent or not
 */
bool IsImmatureCollateral(int nChainHeight, int nCoinsHeight)
{
    return (GetCollateralLockEstimate(nChainHeight, nCoinsHeight) > 0);
}