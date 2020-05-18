/*
 * This file is part of the WarheadCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Log.h"
#include "ScriptMgr.h"
#include "Config.h"
#include "Chat.h"
#include "Player.h"
#include "Battleground.h"

class BGReward_Player : public BGScript
{
public:
    BGReward_Player() : BGScript("BGReward_Player") { }

    void OnBattlegroundEndReward(Battleground* bg, Player* player, TeamId winnerTeamId) override
    {
        if (!sConfigMgr->GetBoolDefault("BGReward.Enable", false))
            return;

        // Not reward on end arena
        if (bg->isArena())
            return;
       
        TeamId bgTeamId = player->GetBgTeamId();
        uint32 RewardCount = 0;

        // Reward ItemID
        uint32 ItemID_WSG       = sConfigMgr->GetIntDefault("BGReward.ItemID.WSG", ITEM_WS_MARK_OF_HONOR);
        uint32 ItemID_ARATHI    = sConfigMgr->GetIntDefault("BGReward.ItemID.Arathi", ITEM_AB_MARK_OF_HONOR);
        uint32 ItemID_ALTERAC   = sConfigMgr->GetIntDefault("BGReward.ItemID.Alterac", ITEM_AV_MARK_OF_HONOR);
        uint32 ItemID_ISLE      = sConfigMgr->GetIntDefault("BGReward.ItemID.Isle", ITEM_IC_MARK_OF_HONOR);
        uint32 ItemID_ANCIENT   = sConfigMgr->GetIntDefault("BGReward.ItemID.Ancients", ITEM_SA_MARK_OF_HONOR);
        uint32 ItemID_EYE       = sConfigMgr->GetIntDefault("BGReward.ItemID.Eye", ITEM_EY_MARK_OF_HONOR);

        // Reward Count
        uint32 WinnerCount      = sConfigMgr->GetIntDefault("BGReward.WinnerTeam.Count", 3);
        uint32 LoserCount       = sConfigMgr->GetIntDefault("BGReward.LoserTeam.Count", 1);

        bgTeamId == winnerTeamId ? (RewardCount = WinnerCount) : (RewardCount = LoserCount);

        switch (player->GetZoneId())
        {
        case 3277: // Warsong Gulch
            player->AddItem(ItemID_WSG, RewardCount);
            break;
        case 3358: // Arathi Basin
            player->AddItem(ItemID_ARATHI, RewardCount);
            break;
        case 3820: // Eye of the Storm
            player->AddItem(ItemID_EYE, RewardCount);
            break;
        case 4710: // Isle of Conquest
            player->AddItem(ItemID_ISLE, RewardCount);
            break;
        case 4384: // Strand of the Ancients
            player->AddItem(ItemID_ANCIENT, RewardCount);
            break;
        case 2597: // Alterac Valley
            player->AddItem(ItemID_ALTERAC, RewardCount);
            break;
        default:
            break;
        }
    }
};


// Group all custom scripts
void AddSC_BGReward()
{
    new BGReward_Player();
}
