TimelockCoin Core integration/staging repository
=====================================

[![Build Status](https://travis-ci.org/TimelockCoin-Project/TimelockCoin.svg?branch=master)](https://travis-ci.org/TimelockCoin-Project/TimelockCoin) [![GitHub version](https://badge.fury.io/gh/TimelockCoin-Project%2FTimelockCoin.svg)](https://badge.fury.io/gh/TimelockCoin-Project%2FTimelockCoin)

TimelockCoin is an open source crypto-currency focused on fast private transactions using the Zerocoin protocol, with low transaction fees & environmental footprint.  It utilizes proof of stake protocol(regular PoS), masternodes and collateral block timelock functionality for securing its network.
The goal of TimelockCoin is to achieve a decentralized sustainable crypto currency that timelock masternode collaterals and funds on the platform for a specific target duration or over a chosen block range.
The first starting masternode collateral of 2.0001234TYM will lock through the block range 1001-10000 blocks.It will unlock after blockheight 10000 while the next collateral of 10.0001234TYM will be locked through blocks 10001 - 15000 before being unlocked. Subsequent masternode logic which will be enforced at different blockheights will lock each variable collateral over its specified and respective block range. 
More information at [timelockcoin.com](http://www.timelockcoin.com).
### Coin Specs
<table>
<tr><td>Algo</td><td>Quark</td></tr>
<tr><td>Block Time</td><td>60 Seconds</td></tr>
<tr><td>Difficulty Retargeting</td><td>Every Block</td></tr>
<tr><td>Total Coin Supply</td><td>50,000,000 TYM</td></tr>
<tr><td>Max Coin Supply (PoS Phase)</td><td>Infinite</td></tr>
<tr><td>Premine</td><td>750,000 TYM*</td></tr>
<tr><td>RPC PORT</td><td>4403</td></tr>
<tr><td>P2P PORT</td><td>4402</td></tr>
</table>

### TYM BLOCK REWARD DISTRIBUTION

<table>
<th>Phase</th><th>BLOCK HEIGHT</th><th>COLLATERAL</th><th>BLOCK REWARD</th><th>MASTERNODE REWARD</th><th>STAKING</th>
<tr><td>Phase 1</td><td>1001 - 10000</td><td>2.0001234 TYM</td><td>0.052 TYM</td><td>0.05 TYM</td><td>0.002 TYM</td></tr>
<tr><td>Phase 2</td><td>10001 - 15000</td><td>10.0001234 TYM</td><td>0.072 TYM</td><td>0.07 TYM</td><td>0.002 TYM</td></tr>
<tr><td>Phase 3</td><td>15001 - 20000</td><td>25.0001234 TYM</td><td>0.122 TYM</td><td>0.12 TYM</td><td>0.002 TYM</td></tr>
<tr><td>Phase 4</td><td>20001 - 25000</td><td>50.0001234 TYM</td><td>0.202 TYM</td><td>0.20 TYM</td><td>0.002 TYM</td></tr>
<tr><td>Phase 5</td><td>25001 - 30000</td><td>100.0001234 TYM</td><td>0.502 TYM</td><td>0.50 TYM</td><td>0.002 TYM</td></tr>
<tr><td>Phase 6</td><td>30001 - 35000</td><td>300.0001234 TYM</td><td>1.602 TYM</td><td>1.60 TYM</td><td>0.002 TYM</td></tr>
<tr><td>Phase 7</td><td>35001 - 40000</td><td>800.0001234 TYM</td><td>3.002 TYM</td><td>3.00 TYM</td><td>0.002 TYM</td></tr>
<tr><td>Phase 8</td><td>40001 - 80000</td><td>5000.0001234 TYM</td><td>30.002 TYM</td><td>30.00 TYM</td><td>0.002 TYM</td></tr>
<tr><td>Phase 9</td><td>80001 - 100000</td><td>5000.0001234 TYM</td><td>25.002 TYM</td><td>25.00 TYM</td><td>0.002 TYM</td></tr>
<tr><td>Phase 10</td><td>100001 - 150000</td><td>5000.0001234 TYM</td><td>20.002 TYM</td><td>20.00 TYM</td><td>0.002 TYM</td></tr>
<tr><td>Phase 11</td><td>150001 - 160000</td><td>5000.0001234 TYM</td><td>15.002 TYM</td><td>15.00 TYM</td><td>0.002 TYM</td></tr>
<tr><td>Phase 12</td><td>160001 - 210001</td><td>5000.0001234 TYM</td><td>10.002 TYM</td><td>10.00 TYM</td><td>0.002 TYM</td></tr>
<tr><td>Phase 13</td><td>210001 - 250000</td><td>5000.0001234 TYM</td><td>5.002 TYM</td><td>5.00 TYM</td><td>0.002 TYM</td></tr>
<tr><td>Phase 14</td><td>250001 - 260000</td><td>5000.0001234 TYM</td><td>4.002 TYM</td><td>4.00 TYM</td><td>0.002 TYM</td></tr>
<tr><td>Phase 15</td><td>260001 - 300000</td><td>5000.0001234 TYM</td><td>3.002 TYM</td><td>3.00 TYM</td><td>0.002 TYM</td></tr>
<tr><td>Phase 16</td><td>300001 - 310000</td><td>5000.0001234 TYM</td><td>2.002 TYM</td><td>2.00 TYM</td><td>0.002 TYM</td></tr>
<tr><td>Phase 17</td><td>310001 - 350000</td><td>5000.0001234 TYM</td><td>1.002 TYM</td><td>1.00 TYM</td><td>0.002 TYM</td></tr>
<tr><td>Phase 18</td><td>350001 - 360000</td><td>5000.0001234 TYM</td><td>0.802 TYM</td><td>0.80 TYM</td><td>0.002 TYM</td></tr>
<tr><td>Phase 19</td><td>360001 - 400000</td><td>5000.0001234 TYM</td><td>0.702 TYM</td><td>0.70 TYM</td><td>0.002 TYM</td></tr>
<tr><td>Phase 20</td><td>400001 - ∞</td><td>5000.0001234 TYM</td><td>0.602 TYM</td><td>0.60 TYM</td><td>0.002 TYM</td></tr>
</table>
