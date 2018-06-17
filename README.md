# BGReward [![Build Status](https://travis-ci.com/Winfidonarleyan/BGReward-module.svg?branch=master)](https://travis-ci.com/Winfidonarleyan/BGReward-module)

### This is a module for [AzerothCore](http://www.azerothcore.org)

#### Features:
- This module notifies the player (who wrote a private message) that his interlocutor can not talk (if his chat is not available)

#### Config option (BGReward.conf.dist)
- BGReward.Enable (Enable/Disable module)

### BGReward Module currently requires:
- AzerothCore v1.0.1+

### How to install
1. Simply place the module under the `modules` folder of your AzerothCore source folder.
2. Re-run cmake and launch a clean build of AzerothCore
3. Apply sql file in DB world `(./sql/world.trinity_string.sql)`
4. (Optional) Edit module configuration (BGReward.conf.dist)
5. Done :)

### Usage
- Write to the player, whose chat is disabled

## Credits
@Winfidonarleyan (author of the module)

@BarbzYHOOL: Best guy

@Talamortis: Almost best guy

AzerothCore: [repository](https://github.com/azerothcore) - [website](http://azerothcore.org/) - [discord chat community](https://discord.gg/PaqQRkd)