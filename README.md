# BGReward [![Build Status](https://travis-ci.com/Winfidonarleyan/BGReward-module.svg?branch=master)](https://travis-ci.com/Winfidonarleyan/BGReward-module)

### This is a module for [AzerothCore](http://www.azerothcore.org)

#### Features:
- If you win or lose on the battleground, you get an additional reward

#### Config option (BGReward.conf.dist)
- BG.Reward.Enable - Enable this module.
- BG.Reward.ItemID.WSG - Reward item on battlegroud Warsong Gulch.
- BG.Reward.ItemID.Arathi - Reward item on battlegroud Arathi Basin.
- BG.Reward.ItemID.Alterac - Reward item on battlegroud Alterac Valley.
- BG.Reward.ItemID.Isle - Reward item on battlegroud Isle of Conquest.
- BG.Reward.ItemID.Ancients - Reward item on battlegroud Strand of the Ancients.
- BG.Reward.ItemID.Eye - Reward item on battlegroud Eye of the Storm.
- BG.Reward.WinnerTeam.Count - Reward count winner battlegroud team.
- BG.Reward.LoserTeam.Count - Reward count loser battlegroud team.

### BGReward Module currently requires:
- Warning! At the moment this module does not work on the official repository until will not be accepted PR (https://github.com/azerothcore/azerothcore-wotlk/pull/929)
- For work need new hooks (https://github.com/Winfidonarleyan/azerothcore-wotlk/commit/049386b93662ad62ea6f779ed5832865ffbde242)
- You can use this repository for testing (https://github.com/Winfidonarleyan/azerothcore-wotlk/tree/bg_hooks)

### How to install
1. Simply place the module under the `modules` folder of your AzerothCore source folder.
2. Re-run cmake and launch a clean build of AzerothCore
3. (Optional) Edit module configuration (BGReward.conf.dist)
4. Done :)

### Usage
- Win or lose BG
- Look your currency

## Credits
* [Winfidonarleyan](https://github.com/Winfidonarleyan) (author of the module): 
* [BarbzYHOOL](https://github.com/barbzyhool): best guy
* [Talamortis](https://github.com/talamortis): almost best guy

AzerothCore: [repository](https://github.com/azerothcore) - [website](http://azerothcore.org/) - [discord chat community](https://discord.gg/PaqQRkd)