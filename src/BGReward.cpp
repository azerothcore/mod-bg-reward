#include "ScriptMgr.h"
#include "Player.h"
#include "Battleground.h"
#include "Configuration/Config.h"

class Kargatum_Reward_Battleground : public BGScript
{
public:
    Kargatum_Reward_Battleground() : BGScript("Kargatum_Reward_Battleground") {}

    void OnBattlegroundEndReward(Battleground* bg, Player* player, TeamId winnerTeamId) override
    {
        if (!sConfigMgr->GetBoolDefault("BG.Reward.Enable", true))
            return;
            
        // Not reward on end arena
        if (bg->isArena())
            return;

        // Reward ItemID
        uint32 ItemID_WSG       = sConfigMgr->GetIntDefault("BG.Reward.ItemID.WSG", 20558);
        uint32 ItemID_ARATHI    = sConfigMgr->GetIntDefault("BG.Reward.ItemID.Arathi", 20559);
        uint32 ItemID_ALTERAC   = sConfigMgr->GetIntDefault("BG.Reward.ItemID.Alterac", 20560);
        uint32 ItemID_ISLE      = sConfigMgr->GetIntDefault("BG.Reward.ItemID.Isle", 47395);
        uint32 ItemID_ANCIENT   = sConfigMgr->GetIntDefault("BG.Reward.ItemID.Ancients", 42425);
        uint32 ItemID_EYE       = sConfigMgr->GetIntDefault("BG.Reward.ItemID.Eye", 29024);

        // Reward Count
        uint32 WinnerCount      = sConfigMgr->GetIntDefault("BG.Reward.WinnerTeam.Count", 3);
        uint32 LoserCount       = sConfigMgr->GetIntDefault("BG.Reward.LoserTeam.Count", 1);

        TeamId bgTeamId = player->GetBgTeamId();
        uint32 RewardCount = 0;

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

class Kargatum_Reward_Battleground_World : public WorldScript
{
public:
    Kargatum_Reward_Battleground_World() : WorldScript("Kargatum_Reward_Battleground_World") {}

    void OnAfterConfigLoad(bool /*reload*/) override
    {
        std::string conf_path = _CONF_DIR;
        std::string cfg_file = conf_path + "/BGReward.conf";

#if PLATFORM == PLATFORM_WINDOWS
        cfg_file = "BGReward.conf";
#endif       
        std::string cfg_def_file = cfg_file + ".dist";

        // Load .conf.dist config
        if (!sConfigMgr->LoadMore(cfg_def_file.c_str()))
        {
            sLog->outString();
            sLog->outError("Module config: Invalid or missing configuration dist file : %s", cfg_def_file.c_str());
            sLog->outError("Module config: Verify that the file exists and has \'[worldserver]' written in the top of the file!");
            sLog->outError("Module config: Use default settings!");
            sLog->outString();
        }

        // Load .conf config
        if (!sConfigMgr->LoadMore(cfg_file.c_str()))
        {
            sLog->outString();
            sLog->outError("Module config: Invalid or missing configuration file : %s", cfg_file.c_str());
            sLog->outError("Module config: Verify that the file exists and has \'[worldserver]' written in the top of the file!");
            sLog->outError("Module config: Use default settings!");
            sLog->outString();
        }
    }
};

void AddBGRewardScripts()
{
	new Kargatum_Reward_Battleground();
    new Kargatum_Reward_Battleground_World();
}
