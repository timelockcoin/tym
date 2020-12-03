TimelockCoin Core integration/staging repository
=====================================

[![Build Status](https://travis-ci.org/TimelockCoin-Project/TimelockCoin.svg?branch=master)](https://travis-ci.org/TimelockCoin-Project/TimelockCoin) [![GitHub version](https://badge.fury.io/gh/TimelockCoin-Project%2FTimelockCoin.svg)](https://badge.fury.io/gh/TimelockCoin-Project%2FTimelockCoin)

TimelockCoin is an open source crypto-currency focused on fast private transactions using the Zerocoin protocol, with low transaction fees & environmental footprint.  It utilizes proof of stake protocol(regular PoS), masternodes and collateral block timelock functionality for securing its network.
The goal of TimelockCoin is to achieve a decentralized sustainable crypto currency that timelock masternode collaterals and funds on the platform for a specific target duration or over a chosen block range.
The first starting masternode collateral of 200.0001234TYM will lock through the block range 501-30000 blocks.It will unlock after blockheight 30000. While the next collateral of 400.0001234TYM will be locked for a 180days duration. Subsequent masternode logic which will be enforced at blockheight 195000 will lock each variable collateral over its specified and respective block range. 
More information at [timelockcoin.com](http://www.timelockcoin.com).
### Coin Specs
<table>
<tr><td>Algo</td><td>Quark</td></tr>
<tr><td>Block Time</td><td>60 Seconds</td></tr>
<tr><td>Difficulty Retargeting</td><td>Every Block</td></tr>
<tr><td>Total Coin Supply</td><td>50,000,000 TYM</td></tr>
<tr><td>Max Coin Supply (PoS Phase)</td><td>Infinite</td></tr>
<tr><td>Premine</td><td>750,000 TYM*</td></tr>
</table>

### TYM BLOCK REWARD DISTRIBUTION

<table>
<th>Phase</th><th>BLOCK HEIGHT</th><th>COLLATERAL</th><th>BLOCK REWARD</th><th>MASTERNODE REWARD</th><th>STAKING</th>
<tr><td>Phase 1</td><td>501 - 3000</td><td>200.0001234 TYM</td><td>0.5 TYM</td><td>0.4995 TYM</td><td>0.0005 TYM</td></tr>
<tr><td>Phase 2</td><td>3001 - 195000</td><td>400.0001234 TYM</td><td>0.85 TYM</td><td>0.8495 TYM</td><td>0.0005 TYM</td></tr>
<tr><td>Phase 3</td><td>195001 - 240000</td><td>1000.0001234 TYM</td><td>1.60 TYM</td><td>1.595 TYM</td><td>0.005 TYM</td></tr>
<tr><td>Phase 4</td><td>240001 - 280000</td><td>2000.0001234 TYM</td><td>2.0 TYM</td><td>1.995 TYM</td><td>0.005 TYM</td></tr>
<tr><td>Phase 5</td><td>280001 - 330000</td><td>3000.0001234 TYM</td><td>2.5 TYM</td><td>2.495 TYM</td><td>0.005 TYM</td></tr>
<tr><td>Phase 6</td><td>330001 - 380000</td><td>4000.0001234 TYM</td><td>3.0 TYM</td><td>2.995 TYM</td><td>0.005 TYM</td></tr>
<tr><td>Phase 7</td><td>380001 - 420000</td><td>7000.0001234 TYM</td><td>3.5 TYM</td><td>3.495 TYM</td><td>0.005 TYM</td></tr>
<tr><td>Phase 8</td><td>420001 - 450000</td><td>8000.0001234 TYM</td><td>4.0 TYM</td><td>3.995 TYM</td><td>0.005 TYM</td></tr>
<tr><td>Phase 9</td><td>450001 - 500000</td><td>9000.0001234 TYM</td><td>4.5 TYM</td><td>4.495 TYM</td><td>0.005 TYM</td></tr>
<tr><td>Phase 10</td><td>500001 - 550000</td><td>13000.0001234 TYM</td><td>6.5 TYM</td><td>6.450 TYM</td><td>0.05 TYM</td></tr>
<tr><td>Phase 11</td><td>550001 - 600000</td><td>15000.0001234 TYM</td><td>8.0 TYM</td><td>7.950 TYM</td><td>0.05 TYM</td></tr>
<tr><td>Phase 12</td><td>600001 - ∞</td><td>20000.0001234 TYM</td><td>10.0 TYM</td><td>9.950 TYM</td><td>0.05 TYM</td></tr>
</table>
