#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "data.h"
#include "event_data.h"
#include "frontier_util.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "menu.h"
#include "palette.h"
#include "recorded_battle.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "trainer_hill.h"
#include "window.h"
#include "constants/battle_dome.h"
#include "constants/battle_string_ids.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/trainers.h"
#include "constants/trainer_hill.h"
#include "constants/weather.h"

struct BattleWindowText
{
    u8 fillValue;
    u8 fontId;
    u8 x;
    u8 y;
    u8 letterSpacing;
    u8 lineSpacing;
    u8 speed;
    u8 fgColor;
    u8 bgColor;
    u8 shadowColor;
};

static void ChooseMoveUsedParticle(u8 *textPtr);
static void ChooseTypeOfMoveUsedString(u8 *dst);
static void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst);

static EWRAM_DATA u8 sBattlerAbilities[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA struct BattleMsgData *gBattleMsgDataPtr = NULL;

// todo: make some of those names less vague: attacker/target vs pkmn, etc.

static const u8 sText_Trainer1LoseText[] = _("{B_TRAINER1_LOSE_TEXT}");
static const u8 sText_PkmnGainedEXP[] = _("{JPN}{B_BUFF1}は{B_BUFF2}\n{B_BUFF3}けいけんちを もらった!\p");
static const u8 sText_PkmnGainedEXPAll[] = _("{JPN}がくしゅうそうちの おかげで\nほかの てもちにも けいけんちが!\p");
static const u8 sText_EmptyString4[] = _("");
static const u8 sText_ABoosted[] = _("{JPN} おおめの");
static const u8 sText_PkmnGrewToLv[] = _("{JPN}{B_BUFF1}は\nレベル {B_BUFF2}に あがった!{WAIT_SE}\p");
static const u8 sText_PkmnLearnedMove[] = _("{JPN}{B_BUFF1}は\n{B_BUFF2}を おぼえた!{WAIT_SE}\p");
static const u8 sText_TryToLearnMove1[] = _("{JPN}{B_BUFF1}は あたらしく\n{B_BUFF2}を おぼえたい......\p");
static const u8 sText_TryToLearnMove2[] = _("{JPN}しかし {B_BUFF1}は わざを\n4つ おぼえているので......\p");
static const u8 sText_TryToLearnMove3[] = _("{JPN}{B_BUFF2}の かわりに\nほかの わざを わすれさせますか?");
static const u8 sText_PkmnForgotMove[] = _("{JPN}{B_BUFF1}は\n{B_BUFF2}を わすれた......\p");
static const u8 sText_StopLearningMove[] = _("{JPN}{PAUSE 32}{B_BUFF2}を\nおぼえるのを あきらめますか?");
static const u8 sText_DidNotLearnMove[] = _("{JPN}{B_BUFF1}は\n{B_BUFF2}を おぼえなかった......\p");
static const u8 sText_UseNextPkmn[] = _("{JPN}つぎの ポケモンを だしますか?");
static const u8 sText_AttackMissed[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の\nこうげきは はずれた!");
static const u8 sText_PkmnProtectedItself[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nみを まもった!");
static const u8 sText_AvoidedDamage[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_DEF_ABILITY}で\nダメージを うけない!");
static const u8 sText_PkmnMakesGroundMiss[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_DEF_ABILITY}で\nじめんわざが あたらない!");
static const u8 sText_PkmnAvoidedAttack[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nこうげきを かわした!");
static const u8 sText_ItDoesntAffect[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}には\nこうかが ないようだ......");
static const u8 sText_AttackerFainted[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nたおれた!\p");
static const u8 sText_TargetFainted[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nたおれた!\p");
static const u8 sText_PlayerGotMoney[] = _("{JPN}{B_PLAYER_NAME}は しょうきんとして\n{B_BUFF1}えん てにいれた!\p");
static const u8 sText_PlayerLostAgainstEnemyTrainer[] = _("{JPN}{B_PLAYER_NAME}は てもちの\nポケモンが すべて たおれた!\p{B_TRAINER1_CLASS} {B_TRAINER1_NAME}との\nしょうぶに まけた!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PlayerPaidPrizeMoney[] = _("{JPN}{B_PLAYER_NAME}は しょうきんとして\n{B_BUFF1}えん はらった......\p... ... ... ...\p{B_PLAYER_NAME}は めのまえが\nまっくらに なった!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PlayerWhiteout[] = _("{JPN}{B_PLAYER_NAME}は てもちの\nポケモンが すべて たおれた!\p");
static const u8 sText_PlayerWhiteout2[] = _("{JPN}{B_PLAYER_NAME}は あわてて\n{B_BUFF1}えん おとしてしまった!\p... ... ... ...\p{B_PLAYER_NAME}は めのまえが\nまっくらに なった!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PreventsEscape[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\nにげられない!\p");
static const u8 sText_CantEscape2[] = _("{JPN}にげられない!\p");
static const u8 sText_AttackerCantEscape[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nにげられない!");
static const u8 sText_HitXTimes[] = _("{JPN}{B_BUFF1}かい あたった!");
static const u8 sText_PkmnFellAsleep[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}は\nねむってしまった!");
static const u8 sText_PkmnMadeSleep[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\n{B_EFF_NAME_WITH_PREFIX}は ねむった!");
static const u8 sText_PkmnAlreadyAsleep[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nすでに ねむっている!");
static const u8 sText_PkmnAlreadyAsleep2[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nすでに ねむっている!");
static const u8 sText_PkmnWasntAffected[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}には\nこうかが なかった!");
static const u8 sText_PkmnWasPoisoned[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}は\nどくを あびた!");
static const u8 sText_PkmnPoisonedBy[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\n{B_EFF_NAME_WITH_PREFIX}は どくを あびた!");
static const u8 sText_PkmnHurtByPoison[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nどくの ダメージを うけた!");
static const u8 sText_PkmnAlreadyPoisoned[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nすでに どくを あびている");
static const u8 sText_PkmnBadlyPoisoned[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}は\nもうどくを あびた!");
static const u8 sText_PkmnEnergyDrained[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}から\nたいりょくを すいとった!");
static const u8 sText_PkmnWasBurned[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}は\nやけどを おった!");
static const u8 sText_PkmnBurnedBy[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\n{B_EFF_NAME_WITH_PREFIX}は やけどを おった!");
static const u8 sText_PkmnHurtByBurn[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nやけどの ダメージを うけた!");
static const u8 sText_PkmnAlreadyHasBurn[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nすでに やけどを おっている");
static const u8 sText_PkmnWasFrozen[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}は\nこおりついてしまった!");
static const u8 sText_PkmnFrozenBy[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\n{B_EFF_NAME_WITH_PREFIX}は こおりついた!");
static const u8 sText_PkmnIsFrozen[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nこおって うごけない!");
static const u8 sText_PkmnWasDefrosted[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nこおりが とけた!");
static const u8 sText_PkmnWasDefrosted2[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nこおりが とけた!");
static const u8 sText_PkmnWasDefrostedBy[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_CURRENT_MOVE}で こおりが とけた!");
static const u8 sText_PkmnWasParalyzed[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}は まひした!\nわざが でにくくなった!");
static const u8 sText_PkmnWasParalyzedBy[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\n{B_EFF_NAME_WITH_PREFIX}は まひした!\lわざが でにくくなった!");
static const u8 sText_PkmnIsParalyzed[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は まひして\nうごけない!");
static const u8 sText_PkmnIsAlreadyParalyzed[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nすでに まひしている!");
static const u8 sText_PkmnHealedParalysis[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の\nまひが なおった!");
static const u8 sText_PkmnDreamEaten[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の\nゆめを たべた!");
static const u8 sText_StatsWontIncrease[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_BUFF1}は\nもう あがらない!");
static const u8 sText_StatsWontDecrease[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_BUFF1}は\nもう さがらない!");
static const u8 sText_TeamStoppedWorking[] = _("{JPN}みかたの {B_BUFF1}の\nこうかが きれた!");
static const u8 sText_FoeStoppedWorking[] = _("{JPN}あいての {B_BUFF1}の\nこうかが きれた!");
static const u8 sText_PkmnIsConfused[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nこんらんしている!");
static const u8 sText_PkmnHealedConfusion[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nこんらんが とけた!");
static const u8 sText_PkmnWasConfused[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}は\nこんらんした!");
static const u8 sText_PkmnAlreadyConfused[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nすでに こんらんしている!");
static const u8 sText_PkmnFellInLove[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nメロメロに なった!");
static const u8 sText_PkmnInLove[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}に メロメロだ!");
static const u8 sText_PkmnImmobilizedByLove[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nメロメロで うごけない!");
static const u8 sText_PkmnBlownAway[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nふきとばされた!");
static const u8 sText_PkmnChangedType[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_BUFF1}タイプに なった!");
static const u8 sText_PkmnFlinched[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nひるんで うごけない!");
static const u8 sText_PkmnRegainedHealth[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nたいりょくを かいふくした!");
static const u8 sText_PkmnHPFull[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の\nHPは まんたんだ!");
static const u8 sText_PkmnRaisedSpDef[] = _("{JPN}{B_ATK_PREFIX2}の {B_CURRENT_MOVE}で\nとくぼうが あがった!");
static const u8 sText_PkmnRaisedSpDefALittle[] = _("{JPN}{B_ATK_PREFIX2}の {B_CURRENT_MOVE}で\nとくぼうが すこし あがった!");
static const u8 sText_PkmnRaisedDef[] = _("{JPN}{B_ATK_PREFIX2}の {B_CURRENT_MOVE}で\nぼうぎょが あがった!");
static const u8 sText_PkmnRaisedDefALittle[] = _("{JPN}{B_ATK_PREFIX2}の {B_CURRENT_MOVE}で\nぼうぎょが すこし あがった!");
static const u8 sText_PkmnCoveredByVeil[] = _("{JPN}{B_ATK_PREFIX2}の みかたは\nしんぴのまもりに つつまれた!");
static const u8 sText_PkmnUsedSafeguard[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の みかたは\nしんぴのまもりに まもられている!");
static const u8 sText_PkmnSafeguardExpired[] = _("{JPN}{B_ATK_PREFIX3}の みかたの\nしんぴのまもりが きれた!");
static const u8 sText_PkmnWentToSleep[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nねむりはじめた!");
static const u8 sText_PkmnSleptHealthy[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ねむって\nげんきに なった!");
static const u8 sText_PkmnWhippedWhirlwind[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nかまいたちを おこした!");
static const u8 sText_PkmnTookSunlight[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nひかりを すいこんだ!");
static const u8 sText_PkmnLoweredHead[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nあたまを さげた!");
static const u8 sText_PkmnIsGlowing[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nひかりはじめた!");
static const u8 sText_PkmnFlewHigh[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nそらたかく とんだ!");
static const u8 sText_PkmnDugHole[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nじめんに もぐった!");
static const u8 sText_PkmnHidUnderwater[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nみずに もぐった!");
static const u8 sText_PkmnSprangUp[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nはねあがった!");
static const u8 sText_PkmnSqueezedByBind[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の しめつけるが\n{B_DEF_NAME_WITH_PREFIX}を しめつけた!");
static const u8 sText_PkmnTrappedInVortex[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nうずに つかまった!");
static const u8 sText_PkmnTrappedBySandTomb[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nすなじごくに つかまった!");
static const u8 sText_PkmnWrappedBy[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_DEF_NAME_WITH_PREFIX}に まきついた!");
static const u8 sText_PkmnClamped[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_DEF_NAME_WITH_PREFIX}に からではさんだ!");
static const u8 sText_PkmnHurtBy[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_BUFF1}の ダメージを うけた!");
static const u8 sText_PkmnFreedFrom[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_BUFF1}から ぬけだした!");
static const u8 sText_PkmnCrashed[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nいきおいあまって しまった!");
const u8 gText_PkmnShroudedInMist[] = _("{JPN}{B_ATK_PREFIX2}は\nしろいきりに つつまれた!");
static const u8 sText_PkmnProtectedByMist[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は\nしろいきりに まもられている!");
const u8 gText_PkmnGettingPumped[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nきあいだめを した!");
static const u8 sText_PkmnHitWithRecoil[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nはんどうで ダメージを うけた!");
static const u8 sText_PkmnProtectedItself2[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nみを まもった!");
static const u8 sText_PkmnBuffetedBySandstorm[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nすなあらしに まかれている!");
static const u8 sText_PkmnPeltedByHail[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nあられに うたれている!");
static const u8 sText_PkmnsXWoreOff[] = _("{JPN}{B_ATK_PREFIX1}の {B_BUFF1}の\nこうかが きれた!");
static const u8 sText_PkmnSeeded[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}に\nタネを つけた!");
static const u8 sText_PkmnEvadedAttack[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nこうげきを かわした!");
static const u8 sText_PkmnSappedByLeechSeed[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nやどりぎに たいりょくを すわれた!");
static const u8 sText_PkmnFastAsleep[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nぐうぐう ねむっている");
static const u8 sText_PkmnWokeUp[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nめを さました!");
static const u8 sText_PkmnUproarKeptAwake[] = _("{JPN}しかし {B_SCR_ACTIVE_NAME_WITH_PREFIX}の さわぎで\nねむれなかった!");
static const u8 sText_PkmnWokeUpInUproar[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は さわぎで\nめを さました!");
static const u8 sText_PkmnCausedUproar[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nさわぎはじめた!");
static const u8 sText_PkmnMakingUproar[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nさわいでいる!");
static const u8 sText_PkmnCalmedDown[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nおちついた");
static const u8 sText_PkmnCantSleepInUproar[] = _("{JPN}しかし {B_DEF_NAME_WITH_PREFIX}は\nさわぎで ねむれない!");
static const u8 sText_PkmnStockpiled[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_BUFF1}かい\nたくわえた!");
static const u8 sText_PkmnCantStockpile[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は これいじょう\nたくわえられない!");
static const u8 sText_PkmnCantSleepInUproar2[] = _("{JPN}しかし {B_DEF_NAME_WITH_PREFIX}は\nさわぎで ねむれない!");
static const u8 sText_UproarKeptPkmnAwake[] = _("{JPN}しかし さわぎで\n{B_DEF_NAME_WITH_PREFIX}は おきてしまった!");
static const u8 sText_PkmnStayedAwakeUsing[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_DEF_ABILITY}で\nおきていた!");
static const u8 sText_PkmnStoringEnergy[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nちからを ためこんでいる!");
static const u8 sText_PkmnUnleashedEnergy[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nちからを ときはなった!");
static const u8 sText_PkmnFatigueConfusion[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は つかれで\nこんらんした!");
static const u8 sText_PlayerPickedUpMoney[] = _("{JPN}{B_PLAYER_NAME}は\n{B_BUFF1}えん ひろった!\p");
static const u8 sText_PkmnUnaffected[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}には\nきかなかった!");
static const u8 sText_PkmnTransformedInto[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_BUFF1}に へんしんした!");
static const u8 sText_PkmnMadeSubstitute[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nみがわりを だした!");
static const u8 sText_PkmnHasSubstitute[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nすでに みがわりが でている!");
static const u8 sText_SubstituteDamaged[] = _("{JPN}みがわりが\n{B_DEF_NAME_WITH_PREFIX}の かわりに ダメージを うけた!\p");
static const u8 sText_PkmnSubstituteFaded[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の\nみがわりが きえた!\p");
static const u8 sText_PkmnMustRecharge[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nこうげきの はんどうで うごけない!");
static const u8 sText_PkmnRageBuilding[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の\nいかりが あがっていく!");
static const u8 sText_PkmnMoveWasDisabled[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_BUFF1}は\nかなしばりで つかえなくなった!");
static const u8 sText_PkmnMoveDisabledNoMore[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の\nかなしばりが とけた!");
static const u8 sText_PkmnGotEncore[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nアンコールを うけた!");
static const u8 sText_PkmnEncoreEnded[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の\nアンコールの こうかが きれた!");
static const u8 sText_PkmnTookAim[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_DEF_NAME_WITH_PREFIX}に ねらいをさだめた!");
static const u8 sText_PkmnSketchedMove[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_BUFF1}を スケッチした!");
static const u8 sText_PkmnTryingToTakeFoe[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nあいてを みちづれに しようとしている!");
static const u8 sText_PkmnTookFoe[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\n{B_ATK_NAME_WITH_PREFIX}を みちづれに した!");
static const u8 sText_PkmnReducedPP[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の\n{B_BUFF1}を {B_BUFF2}へらした!");
static const u8 sText_PkmnStoleItem[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_DEF_NAME_WITH_PREFIX}の {B_LAST_ITEM}を ぬすんだ!");
static const u8 sText_TargetCantEscapeNow[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nもう にげられない!");
static const u8 sText_PkmnFellIntoNightmare[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nあくむを みはじめた!");
static const u8 sText_PkmnLockedInNightmare[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nあくむに うなされている!");
static const u8 sText_PkmnLaidCurse[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は じぶんの HPを けずって\n{B_DEF_NAME_WITH_PREFIX}に のろいをかけた!");
static const u8 sText_PkmnAfflictedByCurse[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nのろいに ダメージを うけた!");
static const u8 sText_SpikesScattered[] = _("{JPN}あいての まわりに\nまきびしを しいた!");
static const u8 sText_PkmnHurtBySpikes[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は\nまきびしの ダメージを うけた!");
static const u8 sText_PkmnIdentified[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_DEF_NAME_WITH_PREFIX}を みやぶった!");
static const u8 sText_PkmnPerishCountFell[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の ほろびのカウントが\n{B_BUFF1}に なった!");
static const u8 sText_PkmnBracedItself[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nこらえる たいせいに はいった!");
static const u8 sText_PkmnEnduredHit[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nこうげきを こらえた!");
static const u8 sText_MagnitudeStrength[] = _("{JPN}マグニチュード{B_BUFF1}!");
static const u8 sText_PkmnCutHPMaxedAttack[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は HPを けずって\nこうげきを さいだいまで あげた!");
static const u8 sText_PkmnCopiedStatChanges[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_DEF_NAME_WITH_PREFIX}の のうりょく へんかを コピーした!");
static const u8 sText_PkmnGotFree[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}の\n{B_BUFF1}から ぬけだした!");
static const u8 sText_PkmnShedLeechSeed[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nやどりぎを はらった!");
static const u8 sText_PkmnBlewAwaySpikes[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nまきびしを ふきとばした!");
static const u8 sText_PkmnFledFromBattle[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nたたかいから にげだした!");
static const u8 sText_PkmnForesawAttack[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nみらいに こうげきを よちした!");
static const u8 sText_PkmnTookAttack[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\n{B_BUFF1}の こうげきを うけた!");
static const u8 sText_PkmnChoseXAsDestiny[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_CURRENT_MOVE}を うんめいに きめた!");
static const u8 sText_PkmnAttack[] = _("{JPN}{B_BUFF1}の こうげき!");
static const u8 sText_PkmnCenterAttention[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nちゅうもくの まとに なった!");
static const u8 sText_PkmnChargingPower[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nちからを ためはじめた!");
static const u8 sText_NaturePowerTurnedInto[] = _("{JPN}しぜんのちからが\n{B_CURRENT_MOVE}に なった!");
static const u8 sText_PkmnStatusNormal[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の じょうたいが\nもとに もどった!");
static const u8 sText_PkmnSubjectedToTorment[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nいちゃもんを つけられた!");
static const u8 sText_PkmnTighteningFocus[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nきあいを こめている!");
static const u8 sText_PkmnFellForTaunt[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nちょうはつに のってしまった!");
static const u8 sText_PkmnReadyToHelp[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_DEF_NAME_WITH_PREFIX}を てだすけした!");
static const u8 sText_PkmnSwitchedItems[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は あいてと\nもちものを こうかんした!");
static const u8 sText_PkmnObtainedX[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_BUFF1}を てにいれた");
static const u8 sText_PkmnObtainedX2[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\n{B_BUFF2}を てにいれた");
static const u8 sText_PkmnObtainedXYObtainedZ[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_BUFF1}を てにいれた\p{B_DEF_NAME_WITH_PREFIX}は\n{B_BUFF2}を てにいれた");
static const u8 sText_PkmnCopiedFoe[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}を コピーした!");
static const u8 sText_PkmnMadeWish[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nねがいごとを した!");
static const u8 sText_PkmnWishCameTrue[] = _("{JPN}{B_BUFF1}の\nねがいが かなった!");
static const u8 sText_PkmnPlantedRoots[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nねを はった!");
static const u8 sText_PkmnAbsorbedNutrients[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nねで たいりょくを すいとった!");
static const u8 sText_PkmnAnchoredItself[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nねを はっている!");
static const u8 sText_PkmnWasMadeDrowsy[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_DEF_NAME_WITH_PREFIX}を\nねむくさせた!");
static const u8 sText_PkmnKnockedOff[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_DEF_NAME_WITH_PREFIX}の {B_LAST_ITEM}を はたきおとした!");
static const u8 sText_PkmnSwappedAbilities[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は あいてと\nとくせいを いれかえた!");
static const u8 sText_PkmnSealedOpponentMove[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nあいての わざを ふういんした!");
static const u8 sText_PkmnWantsGrudge[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nおんねんを こめている!");
static const u8 sText_PkmnLostPPGrudge[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_BUFF1}の PPが\nおんねんで なくなった!");
static const u8 sText_PkmnShroudedItself[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_CURRENT_MOVE}に つつまれた!");
static const u8 sText_PkmnMoveBounced[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_CURRENT_MOVE}は\nマジックコートで はねかえされた!");
static const u8 sText_PkmnWaitsForTarget[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nあいての わざを まっている!");
static const u8 sText_PkmnSnatchedMove[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}の わざを よこどりした!");
static const u8 sText_ElectricityWeakened[] = _("{JPN}でんきの ちからが\nよわまった!");
static const u8 sText_FireWeakened[] = _("{JPN}ほのおの ちからが\nよわまった!");
static const u8 sText_XFoundOneY[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_LAST_ITEM}を みつけた!");
static const u8 sText_SoothingAroma[] = _("{JPN}ここちよい かおりが\nただよってきた!");
static const u8 sText_ItemsCantBeUsedNow[] = _("{JPN}いまは どうぐが つかえません{PAUSE 64}");
static const u8 sText_ForXCommaYZ[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\n{B_BUFF1}");
static const u8 sText_PkmnUsedXToGetPumped[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nきあいを いれた!");
static const u8 sText_PkmnLostFocus[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は しゅうちゅうが\nきれて わざが だせなかった!");
static const u8 sText_PkmnWasDraggedOut[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は\nひきずりだされた!\p");
static const u8 sText_TheWallShattered[] = _("{JPN}かべが くだけた!");
static const u8 sText_ButNoEffect[] = _("{JPN}しかし こうかは なかった!");
static const u8 sText_PkmnHasNoMovesLeft[] = _("{JPN}{B_ACTIVE_NAME_WITH_PREFIX}は\nわざが つかえない!\p");
static const u8 sText_PkmnMoveIsDisabled[] = _("{JPN}{B_ACTIVE_NAME_WITH_PREFIX}の {B_CURRENT_MOVE}は\nかなしばりで つかえない!\p");
static const u8 sText_PkmnCantUseMoveTorment[] = _("{JPN}{B_ACTIVE_NAME_WITH_PREFIX}は いちゃもんで\nおなじわざを つづけて だせない!\p");
static const u8 sText_PkmnCantUseMoveTaunt[] = _("{JPN}{B_ACTIVE_NAME_WITH_PREFIX}は ちょうはつで\n{B_CURRENT_MOVE}が だせない!\p");
static const u8 sText_PkmnCantUseMoveSealed[] = _("{JPN}{B_ACTIVE_NAME_WITH_PREFIX}は ふういんで\n{B_CURRENT_MOVE}が だせない!\p");
static const u8 sText_PkmnMadeItRain[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\nあめが ふりはじめた!");
static const u8 sText_PkmnRaisedSpeed[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\nすばやさが あがった!");
static const u8 sText_PkmnProtectedBy[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_DEF_ABILITY}で\nまもられている!");
static const u8 sText_PkmnPreventsUsage[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\n{B_ATK_NAME_WITH_PREFIX}は\l{B_CURRENT_MOVE}が だせない!");
static const u8 sText_PkmnRestoredHPUsing[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_DEF_ABILITY}で\nHPを かいふくした!");
static const u8 sText_PkmnsXMadeYUseless[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\n{B_CURRENT_MOVE}は きかなかった!");
static const u8 sText_PkmnChangedTypeWith[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_DEF_ABILITY}で\n{B_BUFF1}タイプに なった!");
static const u8 sText_PkmnPreventsParalysisWith[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\nまひに ならない!");
static const u8 sText_PkmnPreventsRomanceWith[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\nメロメロに ならない!");
static const u8 sText_PkmnPreventsPoisoningWith[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\nどくに ならない!");
static const u8 sText_PkmnPreventsConfusionWith[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\nこんらんしない!");
static const u8 sText_PkmnRaisedFirePowerWith[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\nほのおの ちからが あがった!");
static const u8 sText_PkmnAnchorsItselfWith[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_DEF_ABILITY}で\nふんばっている!");
static const u8 sText_PkmnCutsAttackWith[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\n{B_DEF_NAME_WITH_PREFIX}の こうげきが さがった!");
static const u8 sText_PkmnPreventsStatLossWith[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\nのうりょくは さがらない!");
static const u8 sText_PkmnHurtsWith[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\n{B_ATK_NAME_WITH_PREFIX}は ダメージを うけた!");
static const u8 sText_PkmnTraced[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は\n{B_BUFF1}の {B_BUFF2}を トレースした!");
static const u8 sText_PkmnsXPreventsBurns[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}の {B_EFF_ABILITY}で\nやけどに ならない!");
static const u8 sText_PkmnsXBlocksY[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\n{B_CURRENT_MOVE}を ふせいだ!");
static const u8 sText_PkmnsXBlocksY2[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\n{B_CURRENT_MOVE}を ふせいだ!");
static const u8 sText_PkmnsXRestoredHPALittle2[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は {B_ATK_ABILITY}で\nHPを すこし かいふくした!");
static const u8 sText_PkmnsXWhippedUpSandstorm[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\nすなあらしが おきた!");
static const u8 sText_PkmnsXIntensifiedSun[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\nひざしが つよくなった!");
static const u8 sText_PkmnsXPreventsYLoss[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\n{B_BUFF1}は さがらない!");
static const u8 sText_PkmnsXInfatuatedY[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\n{B_ATK_NAME_WITH_PREFIX}は メロメロに なった!");
static const u8 sText_PkmnsXMadeYIneffective[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\n{B_CURRENT_MOVE}は きかなかった!");
static const u8 sText_PkmnsXCuredYProblem[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\n{B_BUFF1}が なおった!");
static const u8 sText_ItSuckedLiquidOoze[] = _("{JPN}ヘドロえきを\nすいとってしまった!");
static const u8 sText_PkmnTransformed[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は\nへんしんした!");
static const u8 sText_PkmnsXTookAttack[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\nこうげきを うけた!");
const u8 gText_PkmnsXPreventsSwitching[] = _("{JPN}{B_BUFF1}の {B_LAST_ABILITY}で\nいれかえることが できない!\p");
static const u8 sText_PreventedFromWorking[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_DEF_ABILITY}で\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}の\l{B_BUFF1}は きかなかった!");
static const u8 sText_PkmnsXMadeItIneffective[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\nこうかが なかった!");
static const u8 sText_PkmnsXPreventsFlinching[] = _("{JPN}{B_EFF_NAME_WITH_PREFIX}の {B_EFF_ABILITY}で\nひるまない!");
static const u8 sText_PkmnsXPreventsYsZ[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_ATK_ABILITY}で\n{B_DEF_NAME_WITH_PREFIX}の\l{B_DEF_ABILITY}は きかない!");
static const u8 sText_PkmnsXCuredItsYProblem[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}で\n{B_BUFF1}が なおった!");
static const u8 sText_PkmnsXHadNoEffectOnY[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の {B_SCR_ACTIVE_ABILITY}は\n{B_EFF_NAME_WITH_PREFIX}には きかなかった!");
static const u8 sText_StatSharply[] = _("{JPN}ぐーんと ");
const u8 gText_StatRose[] = _("{JPN}あがった!");
static const u8 sText_StatHarshly[] = _("{JPN}がくっと ");
static const u8 sText_StatFell[] = _("{JPN}さがった!");
static const u8 sText_AttackersStatRose[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_BUFF1}が\n{B_BUFF2}");
const u8 gText_DefendersStatRose[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_BUFF1}が\n{B_BUFF2}");
static const u8 sText_UsingItemTheStatOfPkmnRose[] = _("{JPN}{B_LAST_ITEM}で {B_SCR_ACTIVE_NAME_WITH_PREFIX}の\n{B_BUFF1}が {B_BUFF2}");
static const u8 sText_AttackersStatFell[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の {B_BUFF1}が\n{B_BUFF2}");
static const u8 sText_DefendersStatFell[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の {B_BUFF1}が\n{B_BUFF2}");
static const u8 sText_StatsWontIncrease2[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の のうりょくは\nもう あがらない!");
static const u8 sText_StatsWontDecrease2[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}の のうりょくは\nもう さがらない!");
static const u8 sText_CriticalHit[] = _("{JPN}きゅうしょに あたった!");
static const u8 sText_OneHitKO[] = _("{JPN}いちげきひっさつ!");
static const u8 sText_123Poof[] = _("{JPN}{PAUSE 32}1 {PAUSE 15}2 {PAUSE 15}......{PAUSE 15}... {PAUSE 15}... {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}やったー!\p");
static const u8 sText_AndEllipsis[] = _("{JPN}それから......\p");
static const u8 sText_HMMovesCantBeForgotten[] = _("{JPN}ひでんわざは いまは\nわすれることが できません!\p");
static const u8 sText_NotVeryEffective[] = _("{JPN}こうかは いまひとつの ようだ......");
static const u8 sText_SuperEffective[] = _("{JPN}こうかは ばつぐんだ!");
static const u8 sText_GotAwaySafely[] = _("{JPN}{PLAY_SE SE_FLEE}うまく にげきれた!\p");
static const u8 sText_PkmnFledUsingIts[] = _("{JPN}{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX}は {B_LAST_ITEM}を\nつかって にげだした!\p");
static const u8 sText_PkmnFledUsing[] = _("{JPN}{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX}は {B_ATK_ABILITY}で\nにげだした!\p");
static const u8 sText_WildPkmnFled[] = _("{JPN}{PLAY_SE SE_FLEE}やせいの {B_BUFF1}は\nにげだした!");
static const u8 sText_PlayerDefeatedLinkTrainer[] = _("{JPN}{B_LINK_OPPONENT1_NAME}に\nかった!");
static const u8 sText_TwoLinkTrainersDefeated[] = _("{JPN}{B_LINK_OPPONENT1_NAME}と\n{B_LINK_OPPONENT2_NAME}に かった!");
static const u8 sText_PlayerLostAgainstLinkTrainer[] = _("{JPN}{B_LINK_OPPONENT1_NAME}に\nまけた!");
static const u8 sText_PlayerLostToTwo[] = _("{JPN}{B_LINK_OPPONENT1_NAME}と\n{B_LINK_OPPONENT2_NAME}に まけた!");
static const u8 sText_PlayerBattledToDrawLinkTrainer[] = _("{JPN}{B_LINK_OPPONENT1_NAME}と\nひきわけた!");
static const u8 sText_PlayerBattledToDrawVsTwo[] = _("{JPN}{B_LINK_OPPONENT1_NAME}と\n{B_LINK_OPPONENT2_NAME}と ひきわけた!");
static const u8 sText_WildFled[] = _("{JPN}{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME}は にげだした!");
static const u8 sText_TwoWildFled[] = _("{JPN}{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME}と\n{B_LINK_OPPONENT2_NAME}は にげだした!");
static const u8 sText_NoRunningFromTrainers[] = _("{JPN}いいえ! トレーナーとの\nしょうぶから にげられない!\p");
static const u8 sText_CantEscape[] = _("{JPN}にげられない!\p");
static const u8 sText_DontLeaveBirch[] = _("{JPN}オダマキはかせ- このままいかないで!\p");
static const u8 sText_ButNothingHappened[] = _("{JPN}しかし なにも おこらなかった!");
static const u8 sText_ButItFailed[] = _("{JPN}しかし うまくいかなかった!");
static const u8 sText_ItHurtConfusion[] = _("{JPN}わけもわからず\nじぶんを こうげきした!");
static const u8 sText_MirrorMoveFailed[] = _("{JPN}オウムがえしは しっぱいした!");
static const u8 sText_StartedToRain[] = _("{JPN}あめが ふりはじめた!");
static const u8 sText_DownpourStarted[] = _("{JPN}おおあめに なった!"); // corresponds to DownpourText in pokegold and pokecrystal and is used by Rain Dance in GSC
static const u8 sText_RainContinues[] = _("{JPN}あめが ふりつづいている");
static const u8 sText_DownpourContinues[] = _("{JPN}おおあめが つづいている"); // unused
static const u8 sText_RainStopped[] = _("{JPN}あめが あがった");
static const u8 sText_SandstormBrewed[] = _("{JPN}すなあらしが ふきはじめた!");
static const u8 sText_SandstormRages[] = _("{JPN}すなあらしが ふきあれている");
static const u8 sText_SandstormSubsided[] = _("{JPN}すなあらしが おさまった");
static const u8 sText_SunlightGotBright[] = _("{JPN}ひざしが つよくなった!");
static const u8 sText_SunlightStrong[] = _("{JPN}ひざしが つよい");
static const u8 sText_SunlightFaded[] = _("{JPN}ひざしが もとにもどった");
static const u8 sText_StartedHail[] = _("{JPN}あられが ふりはじめた!");
static const u8 sText_HailContinues[] = _("{JPN}あられが ふりつづいている");
static const u8 sText_HailStopped[] = _("{JPN}あられが やんだ");
static const u8 sText_FailedToSpitUp[] = _("{JPN}しかし はきだすものが\nなにも なかった!");
static const u8 sText_FailedToSwallow[] = _("{JPN}しかし のみこむものが\nなにも なかった!");
static const u8 sText_WindBecameHeatWave[] = _("{JPN}ねっぷうが\nふきあれた!");
static const u8 sText_StatChangesGone[] = _("{JPN}すべての のうりょく へんかが\nもとに もどった!");
static const u8 sText_CoinsScattered[] = _("{JPN}コインが あたりに ちらばった!");
static const u8 sText_TooWeakForSubstitute[] = _("{JPN}たいりょくが たりず\nみがわりを だせなかった!");
static const u8 sText_SharedPain[] = _("{JPN}おたがいの たいりょくを\nわけあった!");
static const u8 sText_BellChimed[] = _("{JPN}すずの おとが なりひびいた!");
static const u8 sText_FaintInThree[] = _("{JPN}おたがいの ポケモンは\n3ターンごに たおれてしまう!");
static const u8 sText_NoPPLeft[] = _("{JPN}この わざの PPが\nなくなってしまった!\p");
static const u8 sText_ButNoPPLeft[] = _("{JPN}しかし PPが たりない!");
static const u8 sText_PkmnIgnoresAsleep[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nねむったまま いうことを きかない!");
static const u8 sText_PkmnIgnoredOrders[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nいうことを きかない!");
static const u8 sText_PkmnBeganToNap[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nひるねを はじめた!");
static const u8 sText_PkmnLoafing[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nやるきが でない!");
static const u8 sText_PkmnWontObey[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nいうことを きかない!");
static const u8 sText_PkmnTurnedAway[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nそっぽを むいた!");
static const u8 sText_PkmnPretendNotNotice[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\nきづかないフリを した!");
static const u8 sText_EnemyAboutToSwitchPkmn[] = _("{JPN}{B_TRAINER1_CLASS} {B_TRAINER1_NAME}は\n{B_BUFF2}を くりだそうとしている!\p{B_PLAYER_NAME}は ポケモンを\nいれかえますか?");
static const u8 sText_PkmnLearnedMove2[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は\n{B_BUFF1}を おぼえた!");
static const u8 sText_PlayerDefeatedLinkTrainerTrainer1[] = _("{JPN}{B_TRAINER1_CLASS} {B_TRAINER1_NAME}に\nかった!\p");
static const u8 sText_CreptCloser[] = _("{JPN}{B_PLAYER_NAME}は そっと\n{B_OPPONENT_MON1_NAME}に ちかづいた!");
static const u8 sText_CantGetCloser[] = _("{JPN}{B_PLAYER_NAME}は これいじょう\nちかづけない!");
static const u8 sText_PkmnWatchingCarefully[] = _("{JPN}{B_OPPONENT_MON1_NAME}は こちらを\nじっと みている!");
static const u8 sText_PkmnCuriousAboutX[] = _("{JPN}{B_OPPONENT_MON1_NAME}は\n{B_BUFF1}に きょうみしんしんだ!");
static const u8 sText_PkmnEnthralledByX[] = _("{JPN}{B_OPPONENT_MON1_NAME}は\n{B_BUFF1}に むちゅうだ!");
static const u8 sText_PkmnIgnoredX[] = _("{JPN}{B_OPPONENT_MON1_NAME}は\n{B_BUFF1}を まったく むしした!");
static const u8 sText_ThrewPokeblockAtPkmn[] = _("{JPN}{B_PLAYER_NAME}は {POKEBLOCK}を\n{B_OPPONENT_MON1_NAME}に なげた!");
static const u8 sText_OutOfSafariBalls[] = _("{JPN}{PLAY_SE SE_DING_DONG}アナウンス- サファリボールが\nなくなりました! ゲームおわり!\p");
static const u8 sText_OpponentMon1Appeared[] = _("{JPN}{B_OPPONENT_MON1_NAME}が とびだしてきた!\p");
static const u8 sText_WildPkmnAppeared[] = _("{JPN}やせいの {B_OPPONENT_MON1_NAME}が\nとびだしてきた!\p");
static const u8 sText_WildPkmnAppeared_B[] = _("{JPN}やせいの {B_OPPONENT_MON1_NAME}が\nとびだしてきた!\p");
static const u8 sText_WildPkmnAppearedOld[] = _("{JPN}やせいの {B_OPPONENT_MON1_NAME}が\nとびだしてきた!\p");
static const u8 sText_LegendaryPkmnAppeared[] = _("{JPN}やせいの {B_OPPONENT_MON1_NAME}が\nとびだしてきた!\p");
static const u8 sText_WildPkmnAppearedPause[] = _("{JPN}やせいの {B_OPPONENT_MON1_NAME}が\nとびだしてきた!{PAUSE 127}");
static const u8 sText_TwoWildPkmnAppeared[] = _("{JPN}やせいの {B_OPPONENT_MON1_NAME}と\n{B_OPPONENT_MON2_NAME}が とびだしてきた!\p");
static const u8 sText_Trainer1WantsToBattle[] = _("{JPN}{B_TRAINER1_CLASS} {B_TRAINER1_NAME}が\nしょうぶを しかけてきた!\p");
static const u8 sText_LinkTrainerWantsToBattle[] = _("{JPN}{B_LINK_OPPONENT1_NAME}が\nしょうぶを しかけてきた!");
static const u8 sText_TwoLinkTrainersWantToBattle[] = _("{JPN}{B_LINK_OPPONENT1_NAME}と {B_LINK_OPPONENT2_NAME}が\nしょうぶを しかけてきた!");
static const u8 sText_Trainer1SentOutPkmn[] = _("{JPN}{B_TRAINER1_CLASS} {B_TRAINER1_NAME}は\n{B_OPPONENT_MON1_NAME}を くりだした!");
static const u8 sText_Trainer1SentOutTwoPkmn[] = _("{JPN}{B_TRAINER1_CLASS} {B_TRAINER1_NAME}は\n{B_OPPONENT_MON1_NAME}と {B_OPPONENT_MON2_NAME}を くりだした!");
static const u8 sText_Trainer1SentOutPkmn2[] = _("{JPN}{B_TRAINER1_CLASS} {B_TRAINER1_NAME}は\n{B_BUFF1}を くりだした!");
static const u8 sText_LinkTrainerSentOutPkmn[] = _("{JPN}{B_LINK_OPPONENT1_NAME}は\n{B_OPPONENT_MON1_NAME}を くりだした!");
static const u8 sText_LinkTrainerSentOutTwoPkmn[] = _("{JPN}{B_LINK_OPPONENT1_NAME}は\n{B_OPPONENT_MON1_NAME}と {B_OPPONENT_MON2_NAME}を くりだした!");
static const u8 sText_TwoLinkTrainersSentOutPkmn[] = _("{JPN}{B_LINK_OPPONENT1_NAME}は {B_LINK_OPPONENT_MON1_NAME}を!\n{B_LINK_OPPONENT2_NAME}は {B_LINK_OPPONENT_MON2_NAME}を くりだした!");
static const u8 sText_LinkTrainerSentOutPkmn2[] = _("{JPN}{B_LINK_OPPONENT1_NAME}は\n{B_BUFF1}を くりだした!");
static const u8 sText_LinkTrainerMultiSentOutPkmn[] = _("{JPN}{B_LINK_SCR_TRAINER_NAME}は\n{B_BUFF1}を くりだした!");
static const u8 sText_GoPkmn[] = _("{JPN}いけっ! {B_PLAYER_MON1_NAME}!");
static const u8 sText_GoTwoPkmn[] = _("{JPN}いけっ! {B_PLAYER_MON1_NAME}と\n{B_PLAYER_MON2_NAME}!");
static const u8 sText_GoPkmn2[] = _("{JPN}いけっ! {B_BUFF1}!");
static const u8 sText_DoItPkmn[] = _("{JPN}ゆけっ! {B_BUFF1}!");
static const u8 sText_GoForItPkmn[] = _("{JPN}おねがい! {B_BUFF1}!");
static const u8 sText_YourFoesWeakGetEmPkmn[] = _("{JPN}あいては よわっている!\nいけっ {B_BUFF1}!");
static const u8 sText_LinkPartnerSentOutPkmnGoPkmn[] = _("{JPN}{B_LINK_PARTNER_NAME}は {B_LINK_PLAYER_MON2_NAME}を くりだした!\nいけっ! {B_LINK_PLAYER_MON1_NAME}!");
static const u8 sText_PkmnThatsEnough[] = _("{JPN}{B_BUFF1} もういいよ!\nもどれ!");
static const u8 sText_PkmnComeBack[] = _("{JPN}{B_BUFF1} もどれ!");
static const u8 sText_PkmnOkComeBack[] = _("{JPN}{B_BUFF1} よしっ!\nもどれ!");
static const u8 sText_PkmnGoodComeBack[] = _("{JPN}{B_BUFF1} いいぞ!\nもどれ!");
static const u8 sText_Trainer1WithdrewPkmn[] = _("{JPN}{B_TRAINER1_CLASS} {B_TRAINER1_NAME}は\n{B_BUFF1}を ひっこめた!");
static const u8 sText_LinkTrainer1WithdrewPkmn[] = _("{JPN}{B_LINK_OPPONENT1_NAME}は\n{B_BUFF1}を ひっこめた!");
static const u8 sText_LinkTrainer2WithdrewPkmn[] = _("{JPN}{B_LINK_SCR_TRAINER_NAME}は\n{B_BUFF1}を ひっこめた!");
static const u8 sText_WildPkmnPrefix[] = _("{JPN}やせいの ");
static const u8 sText_FoePkmnPrefix[] = _("{JPN}あいての ");
static const u8 sText_EmptyString8[] = _("");
static const u8 sText_FoePkmnPrefix2[] = _("{JPN}あいての");
static const u8 sText_AllyPkmnPrefix[] = _("{JPN}みかたの");
static const u8 sText_FoePkmnPrefix3[] = _("{JPN}あいての");
static const u8 sText_AllyPkmnPrefix2[] = _("{JPN}みかたの");
static const u8 sText_FoePkmnPrefix4[] = _("{JPN}あいての");
static const u8 sText_AllyPkmnPrefix3[] = _("{JPN}みかたの");
static const u8 sText_AttackerUsedX[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}の\n{B_BUFF2}");
static const u8 sText_ExclamationMark[] = _("!");
static const u8 sText_ExclamationMark2[] = _("{JPN}を つかった!");
static const u8 sText_ExclamationMark3[] = _("{JPN}した!");
static const u8 sText_ExclamationMark4[] = _("{JPN}を した!");
static const u8 sText_ExclamationMark5[] = _("{JPN} こうげき!");
static const u8 sText_HP2[] = _("HP");
static const u8 sText_Attack2[] = _("{JPN}こうげき");
static const u8 sText_Defense2[] = _("{JPN}ぼうぎょ");
static const u8 sText_Speed[] = _("{JPN}すばやさ");
static const u8 sText_SpAtk2[] = _("{JPN}とくこう");
static const u8 sText_SpDef2[] = _("{JPN}とくぼう");
static const u8 sText_Accuracy[] = _("{JPN}めいちゅうりつ");
static const u8 sText_Evasiveness[] = _("{JPN}かいひりつ");

const u8 * const gStatNamesTable[NUM_BATTLE_STATS] =
{
    [STAT_HP]      = sText_HP2,
    [STAT_ATK]     = sText_Attack2,
    [STAT_DEF]     = sText_Defense2,
    [STAT_SPEED]   = sText_Speed,
    [STAT_SPATK]   = sText_SpAtk2,
    [STAT_SPDEF]   = sText_SpDef2,
    [STAT_ACC]     = sText_Accuracy,
    [STAT_EVASION] = sText_Evasiveness,
};

static const u8 sText_PokeblockWasTooSpicy[] = _("{JPN}からすぎた!");
static const u8 sText_PokeblockWasTooDry[] = _("{JPN}しぶすぎた!");
static const u8 sText_PokeblockWasTooSweet[] = _("{JPN}あますぎた!");
static const u8 sText_PokeblockWasTooBitter[] = _("{JPN}にがすぎた!");
static const u8 sText_PokeblockWasTooSour[] = _("{JPN}すっぱすぎた!");

const u8 * const gPokeblockWasTooXStringTable[FLAVOR_COUNT] =
{
    [FLAVOR_SPICY]  = sText_PokeblockWasTooSpicy,
    [FLAVOR_DRY]    = sText_PokeblockWasTooDry,
    [FLAVOR_SWEET]  = sText_PokeblockWasTooSweet,
    [FLAVOR_BITTER] = sText_PokeblockWasTooBitter,
    [FLAVOR_SOUR]   = sText_PokeblockWasTooSour
};

static const u8 sText_PlayerUsedItem[] = _("{JPN}{B_PLAYER_NAME}は\n{B_LAST_ITEM}を つかった!");
static const u8 sText_WallyUsedItem[] = _("{JPN}ミツルは\n{B_LAST_ITEM}を つかった!");
static const u8 sText_Trainer1UsedItem[] = _("{JPN}{B_TRAINER1_CLASS} {B_TRAINER1_NAME}は\n{B_LAST_ITEM}を つかった!");
static const u8 sText_TrainerBlockedBall[] = _("{JPN}トレーナーが ボールを\nはたきおとした!");
static const u8 sText_DontBeAThief[] = _("{JPN}ひとの ものを とるのは\nどろぼう!");
static const u8 sText_ItDodgedBall[] = _("{JPN}ボールを よけられた!\nこの ポケモンは つかまえられない!");
static const u8 sText_YouMissedPkmn[] = _("{JPN}ボールが はずれた!");
static const u8 sText_PkmnBrokeFree[] = _("{JPN}あっ!\nポケモンが とびだしてきた!");
static const u8 sText_ItAppearedCaught[] = _("{JPN}あーっ!\nつかまえたと おもったのに!");
static const u8 sText_AarghAlmostHadIt[] = _("{JPN}おしい!\nもうすこしだったのに!");
static const u8 sText_ShootSoClose[] = _("{JPN}あーっ!\nもうちょっとだったのに!");
static const u8 sText_GotchaPkmnCaughtPlayer[] = _("{JPN}やったー!\n{B_OPPONENT_MON1_NAME}を つかまえたぞ!{WAIT_SE}\p");
static const u8 sText_GotchaPkmnCaughtWally[] = _("{JPN}やったー!\n{B_OPPONENT_MON1_NAME}を つかまえたぞ!{WAIT_SE}{PAUSE 127}");
static const u8 sText_GiveNicknameCaptured[] = _("{JPN}つかまえた {B_OPPONENT_MON1_NAME}に\nニックネームを つけますか?");
static const u8 sText_PkmnSentToPC[] = _("{JPN}{B_OPPONENT_MON1_NAME}は\n{B_PC_CREATOR_NAME}パソコンに てんそうされた");
static const u8 sText_Someones[] = _("{JPN}だれかの");
static const u8 sText_Bills[] = _("{JPN}マユミの");
static const u8 sText_PkmnDataAddedToDex[] = _("{JPN}{B_OPPONENT_MON1_NAME}の データが\nずかんに ついかされた!\p");
static const u8 sText_ItIsRaining[] = _("{JPN}あめが ふっている");
static const u8 sText_SandstormIsRaging[] = _("{JPN}すなあらしが ふいている");
static const u8 sText_BoxIsFull[] = _("{JPN}ボックスが いっぱいです!\nもう つかまえられません!\p");
static const u8 sText_EnigmaBerry[] = _("{JPN}ナゾのみ");
static const u8 sText_BerrySuffix[] = _("{JPN}のみ");
static const u8 sText_PkmnsItemCuredParalysis[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nまひが なおった!");
static const u8 sText_PkmnsItemCuredPoison[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nどくが なおった!");
static const u8 sText_PkmnsItemHealedBurn[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nやけどが なおった!");
static const u8 sText_PkmnsItemDefrostedIt[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nこおりが とけた!");
static const u8 sText_PkmnsItemWokeIt[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nめが さめた!");
static const u8 sText_PkmnsItemSnappedOut[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nこんらんが とけた!");
static const u8 sText_PkmnsItemCuredProblem[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\n{B_BUFF1}が なおった!");
static const u8 sText_PkmnsItemNormalizedStatus[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nじょうたいが もとに もどった!");
static const u8 sText_PkmnsItemRestoredHealth[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nたいりょくを かいふくした!");
static const u8 sText_PkmnsItemRestoredPP[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\n{B_BUFF1}の PPを かいふくした!");
static const u8 sText_PkmnsItemRestoredStatus[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nじょうたいを かいふくした!");
static const u8 sText_PkmnsItemRestoredHPALittle[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nHPを すこし かいふくした!");
static const u8 sText_ItemAllowsOnlyYMove[] = _("{JPN}{B_LAST_ITEM}の こうかで\n{B_CURRENT_MOVE}しか だせない!\p");
static const u8 sText_PkmnHungOnWithX[] = _("{JPN}{B_DEF_NAME_WITH_PREFIX}は {B_LAST_ITEM}で\nもちこたえた!");
const u8 gText_EmptyString3[] = _("");
static const u8 sText_YouThrowABallNowRight[] = _("{JPN}ボールを なげるんだね?\nぼくも がんばるよ!");
static const u8 sText_PkmnDroppedItem[] = _("{JPN}{B_OPPONENT_MON1_NAME}は\n{B_LAST_ITEM}を おとした!{WAIT_SE}\p");
static const u8 sText_BagIsFull[] = _("{JPN}{B_OPPONENT_MON1_NAME}は\n{B_LAST_ITEM}を おとした!{WAIT_SE}\pしかし バッグが いっぱいだ!\p");

// early declaration of strings
static const u8 sText_PkmnIncapableOfPower[];
static const u8 sText_GlintAppearsInEye[];
static const u8 sText_PkmnGettingIntoPosition[];
static const u8 sText_PkmnBeganGrowlingDeeply[];
static const u8 sText_PkmnEagerForMore[];
static const u8 sText_DefeatedOpponentByReferee[];
static const u8 sText_LostToOpponentByReferee[];
static const u8 sText_TiedOpponentByReferee[];
static const u8 sText_QuestionForfeitMatch[];
static const u8 sText_ForfeitedMatch[];
static const u8 sText_Trainer1WinText[];
static const u8 sText_Trainer2WinText[];
static const u8 sText_TwoInGameTrainersDefeated[];
static const u8 sText_Trainer2LoseText[];

const u8 * const gBattleStringsTable[BATTLESTRINGS_COUNT - BATTLESTRINGS_TABLE_START] =
{
    [STRINGID_TRAINER1LOSETEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer1LoseText,
    [STRINGID_PKMNGAINEDEXP - BATTLESTRINGS_TABLE_START] = sText_PkmnGainedEXP,
    [STRINGID_PKMNGREWTOLV - BATTLESTRINGS_TABLE_START] = sText_PkmnGrewToLv,
    [STRINGID_PKMNLEARNEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnLearnedMove,
    [STRINGID_TRYTOLEARNMOVE1 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove1,
    [STRINGID_TRYTOLEARNMOVE2 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove2,
    [STRINGID_TRYTOLEARNMOVE3 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove3,
    [STRINGID_PKMNFORGOTMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnForgotMove,
    [STRINGID_STOPLEARNINGMOVE - BATTLESTRINGS_TABLE_START] = sText_StopLearningMove,
    [STRINGID_DIDNOTLEARNMOVE - BATTLESTRINGS_TABLE_START] = sText_DidNotLearnMove,
    [STRINGID_PKMNLEARNEDMOVE2 - BATTLESTRINGS_TABLE_START] = sText_PkmnLearnedMove2,
    [STRINGID_ATTACKMISSED - BATTLESTRINGS_TABLE_START] = sText_AttackMissed,
    [STRINGID_PKMNPROTECTEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedItself,
    [STRINGID_STATSWONTINCREASE2 - BATTLESTRINGS_TABLE_START] = sText_StatsWontIncrease2,
    [STRINGID_AVOIDEDDAMAGE - BATTLESTRINGS_TABLE_START] = sText_AvoidedDamage,
    [STRINGID_ITDOESNTAFFECT - BATTLESTRINGS_TABLE_START] = sText_ItDoesntAffect,
    [STRINGID_ATTACKERFAINTED - BATTLESTRINGS_TABLE_START] = sText_AttackerFainted,
    [STRINGID_TARGETFAINTED - BATTLESTRINGS_TABLE_START] = sText_TargetFainted,
    [STRINGID_PLAYERGOTMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerGotMoney,
    [STRINGID_PLAYERLOSTAGAINSTENEMYTRAINER - BATTLESTRINGS_TABLE_START] = sText_PlayerLostAgainstEnemyTrainer,
    [STRINGID_PLAYERPAIDPRIZEMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerPaidPrizeMoney,
    [STRINGID_PLAYERWHITEOUT - BATTLESTRINGS_TABLE_START] = sText_PlayerWhiteout,
    [STRINGID_PLAYERWHITEOUT2 - BATTLESTRINGS_TABLE_START] = sText_PlayerWhiteout2,
    [STRINGID_PREVENTSESCAPE - BATTLESTRINGS_TABLE_START] = sText_PreventsEscape,
    [STRINGID_HITXTIMES - BATTLESTRINGS_TABLE_START] = sText_HitXTimes,
    [STRINGID_PKMNFELLASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnFellAsleep,
    [STRINGID_PKMNMADESLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeSleep,
    [STRINGID_PKMNALREADYASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyAsleep,
    [STRINGID_PKMNALREADYASLEEP2 - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyAsleep2,
    [STRINGID_PKMNWASNTAFFECTED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasntAffected,
    [STRINGID_PKMNWASPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasPoisoned,
    [STRINGID_PKMNPOISONEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnPoisonedBy,
    [STRINGID_PKMNHURTBYPOISON - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByPoison,
    [STRINGID_PKMNALREADYPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyPoisoned,
    [STRINGID_PKMNBADLYPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnBadlyPoisoned,
    [STRINGID_PKMNENERGYDRAINED - BATTLESTRINGS_TABLE_START] = sText_PkmnEnergyDrained,
    [STRINGID_PKMNWASBURNED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasBurned,
    [STRINGID_PKMNBURNEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnBurnedBy,
    [STRINGID_PKMNHURTBYBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByBurn,
    [STRINGID_PKMNWASFROZEN - BATTLESTRINGS_TABLE_START] = sText_PkmnWasFrozen,
    [STRINGID_PKMNFROZENBY - BATTLESTRINGS_TABLE_START] = sText_PkmnFrozenBy,
    [STRINGID_PKMNISFROZEN - BATTLESTRINGS_TABLE_START] = sText_PkmnIsFrozen,
    [STRINGID_PKMNWASDEFROSTED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrosted,
    [STRINGID_PKMNWASDEFROSTED2 - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrosted2,
    [STRINGID_PKMNWASDEFROSTEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrostedBy,
    [STRINGID_PKMNWASPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasParalyzed,
    [STRINGID_PKMNWASPARALYZEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasParalyzedBy,
    [STRINGID_PKMNISPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsParalyzed,
    [STRINGID_PKMNISALREADYPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsAlreadyParalyzed,
    [STRINGID_PKMNHEALEDPARALYSIS - BATTLESTRINGS_TABLE_START] = sText_PkmnHealedParalysis,
    [STRINGID_PKMNDREAMEATEN - BATTLESTRINGS_TABLE_START] = sText_PkmnDreamEaten,
    [STRINGID_STATSWONTINCREASE - BATTLESTRINGS_TABLE_START] = sText_StatsWontIncrease,
    [STRINGID_STATSWONTDECREASE - BATTLESTRINGS_TABLE_START] = sText_StatsWontDecrease,
    [STRINGID_TEAMSTOPPEDWORKING - BATTLESTRINGS_TABLE_START] = sText_TeamStoppedWorking,
    [STRINGID_FOESTOPPEDWORKING - BATTLESTRINGS_TABLE_START] = sText_FoeStoppedWorking,
    [STRINGID_PKMNISCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsConfused,
    [STRINGID_PKMNHEALEDCONFUSION - BATTLESTRINGS_TABLE_START] = sText_PkmnHealedConfusion,
    [STRINGID_PKMNWASCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasConfused,
    [STRINGID_PKMNALREADYCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyConfused,
    [STRINGID_PKMNFELLINLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnFellInLove,
    [STRINGID_PKMNINLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnInLove,
    [STRINGID_PKMNIMMOBILIZEDBYLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnImmobilizedByLove,
    [STRINGID_PKMNBLOWNAWAY - BATTLESTRINGS_TABLE_START] = sText_PkmnBlownAway,
    [STRINGID_PKMNCHANGEDTYPE - BATTLESTRINGS_TABLE_START] = sText_PkmnChangedType,
    [STRINGID_PKMNFLINCHED - BATTLESTRINGS_TABLE_START] = sText_PkmnFlinched,
    [STRINGID_PKMNREGAINEDHEALTH - BATTLESTRINGS_TABLE_START] = sText_PkmnRegainedHealth,
    [STRINGID_PKMNHPFULL - BATTLESTRINGS_TABLE_START] = sText_PkmnHPFull,
    [STRINGID_PKMNRAISEDSPDEF - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpDef,
    [STRINGID_PKMNRAISEDDEF - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedDef,
    [STRINGID_PKMNCOVEREDBYVEIL - BATTLESTRINGS_TABLE_START] = sText_PkmnCoveredByVeil,
    [STRINGID_PKMNUSEDSAFEGUARD - BATTLESTRINGS_TABLE_START] = sText_PkmnUsedSafeguard,
    [STRINGID_PKMNSAFEGUARDEXPIRED - BATTLESTRINGS_TABLE_START] = sText_PkmnSafeguardExpired,
    [STRINGID_PKMNWENTTOSLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnWentToSleep,
    [STRINGID_PKMNSLEPTHEALTHY - BATTLESTRINGS_TABLE_START] = sText_PkmnSleptHealthy,
    [STRINGID_PKMNWHIPPEDWHIRLWIND - BATTLESTRINGS_TABLE_START] = sText_PkmnWhippedWhirlwind,
    [STRINGID_PKMNTOOKSUNLIGHT - BATTLESTRINGS_TABLE_START] = sText_PkmnTookSunlight,
    [STRINGID_PKMNLOWEREDHEAD - BATTLESTRINGS_TABLE_START] = sText_PkmnLoweredHead,
    [STRINGID_PKMNISGLOWING - BATTLESTRINGS_TABLE_START] = sText_PkmnIsGlowing,
    [STRINGID_PKMNFLEWHIGH - BATTLESTRINGS_TABLE_START] = sText_PkmnFlewHigh,
    [STRINGID_PKMNDUGHOLE - BATTLESTRINGS_TABLE_START] = sText_PkmnDugHole,
    [STRINGID_PKMNSQUEEZEDBYBIND - BATTLESTRINGS_TABLE_START] = sText_PkmnSqueezedByBind,
    [STRINGID_PKMNTRAPPEDINVORTEX - BATTLESTRINGS_TABLE_START] = sText_PkmnTrappedInVortex,
    [STRINGID_PKMNWRAPPEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWrappedBy,
    [STRINGID_PKMNCLAMPED - BATTLESTRINGS_TABLE_START] = sText_PkmnClamped,
    [STRINGID_PKMNHURTBY - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtBy,
    [STRINGID_PKMNFREEDFROM - BATTLESTRINGS_TABLE_START] = sText_PkmnFreedFrom,
    [STRINGID_PKMNCRASHED - BATTLESTRINGS_TABLE_START] = sText_PkmnCrashed,
    [STRINGID_PKMNSHROUDEDINMIST - BATTLESTRINGS_TABLE_START] = gText_PkmnShroudedInMist,
    [STRINGID_PKMNPROTECTEDBYMIST - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedByMist,
    [STRINGID_PKMNGETTINGPUMPED - BATTLESTRINGS_TABLE_START] = gText_PkmnGettingPumped,
    [STRINGID_PKMNHITWITHRECOIL - BATTLESTRINGS_TABLE_START] = sText_PkmnHitWithRecoil,
    [STRINGID_PKMNPROTECTEDITSELF2 - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedItself2,
    [STRINGID_PKMNBUFFETEDBYSANDSTORM - BATTLESTRINGS_TABLE_START] = sText_PkmnBuffetedBySandstorm,
    [STRINGID_PKMNPELTEDBYHAIL - BATTLESTRINGS_TABLE_START] = sText_PkmnPeltedByHail,
    [STRINGID_PKMNSEEDED - BATTLESTRINGS_TABLE_START] = sText_PkmnSeeded,
    [STRINGID_PKMNEVADEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnEvadedAttack,
    [STRINGID_PKMNSAPPEDBYLEECHSEED - BATTLESTRINGS_TABLE_START] = sText_PkmnSappedByLeechSeed,
    [STRINGID_PKMNFASTASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnFastAsleep,
    [STRINGID_PKMNWOKEUP - BATTLESTRINGS_TABLE_START] = sText_PkmnWokeUp,
    [STRINGID_PKMNUPROARKEPTAWAKE - BATTLESTRINGS_TABLE_START] = sText_PkmnUproarKeptAwake,
    [STRINGID_PKMNWOKEUPINUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnWokeUpInUproar,
    [STRINGID_PKMNCAUSEDUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnCausedUproar,
    [STRINGID_PKMNMAKINGUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnMakingUproar,
    [STRINGID_PKMNCALMEDDOWN - BATTLESTRINGS_TABLE_START] = sText_PkmnCalmedDown,
    [STRINGID_PKMNCANTSLEEPINUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnCantSleepInUproar,
    [STRINGID_PKMNSTOCKPILED - BATTLESTRINGS_TABLE_START] = sText_PkmnStockpiled,
    [STRINGID_PKMNCANTSTOCKPILE - BATTLESTRINGS_TABLE_START] = sText_PkmnCantStockpile,
    [STRINGID_PKMNCANTSLEEPINUPROAR2 - BATTLESTRINGS_TABLE_START] = sText_PkmnCantSleepInUproar2,
    [STRINGID_UPROARKEPTPKMNAWAKE - BATTLESTRINGS_TABLE_START] = sText_UproarKeptPkmnAwake,
    [STRINGID_PKMNSTAYEDAWAKEUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnStayedAwakeUsing,
    [STRINGID_PKMNSTORINGENERGY - BATTLESTRINGS_TABLE_START] = sText_PkmnStoringEnergy,
    [STRINGID_PKMNUNLEASHEDENERGY - BATTLESTRINGS_TABLE_START] = sText_PkmnUnleashedEnergy,
    [STRINGID_PKMNFATIGUECONFUSION - BATTLESTRINGS_TABLE_START] = sText_PkmnFatigueConfusion,
    [STRINGID_PLAYERPICKEDUPMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerPickedUpMoney,
    [STRINGID_PKMNUNAFFECTED - BATTLESTRINGS_TABLE_START] = sText_PkmnUnaffected,
    [STRINGID_PKMNTRANSFORMEDINTO - BATTLESTRINGS_TABLE_START] = sText_PkmnTransformedInto,
    [STRINGID_PKMNMADESUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeSubstitute,
    [STRINGID_PKMNHASSUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_PkmnHasSubstitute,
    [STRINGID_SUBSTITUTEDAMAGED - BATTLESTRINGS_TABLE_START] = sText_SubstituteDamaged,
    [STRINGID_PKMNSUBSTITUTEFADED - BATTLESTRINGS_TABLE_START] = sText_PkmnSubstituteFaded,
    [STRINGID_PKMNMUSTRECHARGE - BATTLESTRINGS_TABLE_START] = sText_PkmnMustRecharge,
    [STRINGID_PKMNRAGEBUILDING - BATTLESTRINGS_TABLE_START] = sText_PkmnRageBuilding,
    [STRINGID_PKMNMOVEWASDISABLED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveWasDisabled,
    [STRINGID_PKMNMOVEISDISABLED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveIsDisabled,
    [STRINGID_PKMNMOVEDISABLEDNOMORE - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveDisabledNoMore,
    [STRINGID_PKMNGOTENCORE - BATTLESTRINGS_TABLE_START] = sText_PkmnGotEncore,
    [STRINGID_PKMNENCOREENDED - BATTLESTRINGS_TABLE_START] = sText_PkmnEncoreEnded,
    [STRINGID_PKMNTOOKAIM - BATTLESTRINGS_TABLE_START] = sText_PkmnTookAim,
    [STRINGID_PKMNSKETCHEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSketchedMove,
    [STRINGID_PKMNTRYINGTOTAKEFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnTryingToTakeFoe,
    [STRINGID_PKMNTOOKFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnTookFoe,
    [STRINGID_PKMNREDUCEDPP - BATTLESTRINGS_TABLE_START] = sText_PkmnReducedPP,
    [STRINGID_PKMNSTOLEITEM - BATTLESTRINGS_TABLE_START] = sText_PkmnStoleItem,
    [STRINGID_TARGETCANTESCAPENOW - BATTLESTRINGS_TABLE_START] = sText_TargetCantEscapeNow,
    [STRINGID_PKMNFELLINTONIGHTMARE - BATTLESTRINGS_TABLE_START] = sText_PkmnFellIntoNightmare,
    [STRINGID_PKMNLOCKEDINNIGHTMARE - BATTLESTRINGS_TABLE_START] = sText_PkmnLockedInNightmare,
    [STRINGID_PKMNLAIDCURSE - BATTLESTRINGS_TABLE_START] = sText_PkmnLaidCurse,
    [STRINGID_PKMNAFFLICTEDBYCURSE - BATTLESTRINGS_TABLE_START] = sText_PkmnAfflictedByCurse,
    [STRINGID_SPIKESSCATTERED - BATTLESTRINGS_TABLE_START] = sText_SpikesScattered,
    [STRINGID_PKMNHURTBYSPIKES - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtBySpikes,
    [STRINGID_PKMNIDENTIFIED - BATTLESTRINGS_TABLE_START] = sText_PkmnIdentified,
    [STRINGID_PKMNPERISHCOUNTFELL - BATTLESTRINGS_TABLE_START] = sText_PkmnPerishCountFell,
    [STRINGID_PKMNBRACEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnBracedItself,
    [STRINGID_PKMNENDUREDHIT - BATTLESTRINGS_TABLE_START] = sText_PkmnEnduredHit,
    [STRINGID_MAGNITUDESTRENGTH - BATTLESTRINGS_TABLE_START] = sText_MagnitudeStrength,
    [STRINGID_PKMNCUTHPMAXEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnCutHPMaxedAttack,
    [STRINGID_PKMNCOPIEDSTATCHANGES - BATTLESTRINGS_TABLE_START] = sText_PkmnCopiedStatChanges,
    [STRINGID_PKMNGOTFREE - BATTLESTRINGS_TABLE_START] = sText_PkmnGotFree,
    [STRINGID_PKMNSHEDLEECHSEED - BATTLESTRINGS_TABLE_START] = sText_PkmnShedLeechSeed,
    [STRINGID_PKMNBLEWAWAYSPIKES - BATTLESTRINGS_TABLE_START] = sText_PkmnBlewAwaySpikes,
    [STRINGID_PKMNFLEDFROMBATTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnFledFromBattle,
    [STRINGID_PKMNFORESAWATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnForesawAttack,
    [STRINGID_PKMNTOOKATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnTookAttack,
    [STRINGID_PKMNATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnAttack,
    [STRINGID_PKMNCENTERATTENTION - BATTLESTRINGS_TABLE_START] = sText_PkmnCenterAttention,
    [STRINGID_PKMNCHARGINGPOWER - BATTLESTRINGS_TABLE_START] = sText_PkmnChargingPower,
    [STRINGID_NATUREPOWERTURNEDINTO - BATTLESTRINGS_TABLE_START] = sText_NaturePowerTurnedInto,
    [STRINGID_PKMNSTATUSNORMAL - BATTLESTRINGS_TABLE_START] = sText_PkmnStatusNormal,
    [STRINGID_PKMNHASNOMOVESLEFT - BATTLESTRINGS_TABLE_START] = sText_PkmnHasNoMovesLeft,
    [STRINGID_PKMNSUBJECTEDTOTORMENT - BATTLESTRINGS_TABLE_START] = sText_PkmnSubjectedToTorment,
    [STRINGID_PKMNCANTUSEMOVETORMENT - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveTorment,
    [STRINGID_PKMNTIGHTENINGFOCUS - BATTLESTRINGS_TABLE_START] = sText_PkmnTighteningFocus,
    [STRINGID_PKMNFELLFORTAUNT - BATTLESTRINGS_TABLE_START] = sText_PkmnFellForTaunt,
    [STRINGID_PKMNCANTUSEMOVETAUNT - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveTaunt,
    [STRINGID_PKMNREADYTOHELP - BATTLESTRINGS_TABLE_START] = sText_PkmnReadyToHelp,
    [STRINGID_PKMNSWITCHEDITEMS - BATTLESTRINGS_TABLE_START] = sText_PkmnSwitchedItems,
    [STRINGID_PKMNCOPIEDFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnCopiedFoe,
    [STRINGID_PKMNMADEWISH - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeWish,
    [STRINGID_PKMNWISHCAMETRUE - BATTLESTRINGS_TABLE_START] = sText_PkmnWishCameTrue,
    [STRINGID_PKMNPLANTEDROOTS - BATTLESTRINGS_TABLE_START] = sText_PkmnPlantedRoots,
    [STRINGID_PKMNABSORBEDNUTRIENTS - BATTLESTRINGS_TABLE_START] = sText_PkmnAbsorbedNutrients,
    [STRINGID_PKMNANCHOREDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnAnchoredItself,
    [STRINGID_PKMNWASMADEDROWSY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasMadeDrowsy,
    [STRINGID_PKMNKNOCKEDOFF - BATTLESTRINGS_TABLE_START] = sText_PkmnKnockedOff,
    [STRINGID_PKMNSWAPPEDABILITIES - BATTLESTRINGS_TABLE_START] = sText_PkmnSwappedAbilities,
    [STRINGID_PKMNSEALEDOPPONENTMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSealedOpponentMove,
    [STRINGID_PKMNCANTUSEMOVESEALED - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveSealed,
    [STRINGID_PKMNWANTSGRUDGE - BATTLESTRINGS_TABLE_START] = sText_PkmnWantsGrudge,
    [STRINGID_PKMNLOSTPPGRUDGE - BATTLESTRINGS_TABLE_START] = sText_PkmnLostPPGrudge,
    [STRINGID_PKMNSHROUDEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnShroudedItself,
    [STRINGID_PKMNMOVEBOUNCED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveBounced,
    [STRINGID_PKMNWAITSFORTARGET - BATTLESTRINGS_TABLE_START] = sText_PkmnWaitsForTarget,
    [STRINGID_PKMNSNATCHEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSnatchedMove,
    [STRINGID_PKMNMADEITRAIN - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeItRain,
    [STRINGID_PKMNRAISEDSPEED - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpeed,
    [STRINGID_PKMNPROTECTEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedBy,
    [STRINGID_PKMNPREVENTSUSAGE - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsUsage,
    [STRINGID_PKMNRESTOREDHPUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnRestoredHPUsing,
    [STRINGID_PKMNCHANGEDTYPEWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnChangedTypeWith,
    [STRINGID_PKMNPREVENTSPARALYSISWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsParalysisWith,
    [STRINGID_PKMNPREVENTSROMANCEWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsRomanceWith,
    [STRINGID_PKMNPREVENTSPOISONINGWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsPoisoningWith,
    [STRINGID_PKMNPREVENTSCONFUSIONWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsConfusionWith,
    [STRINGID_PKMNRAISEDFIREPOWERWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedFirePowerWith,
    [STRINGID_PKMNANCHORSITSELFWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnAnchorsItselfWith,
    [STRINGID_PKMNCUTSATTACKWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnCutsAttackWith,
    [STRINGID_PKMNPREVENTSSTATLOSSWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsStatLossWith,
    [STRINGID_PKMNHURTSWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtsWith,
    [STRINGID_PKMNTRACED - BATTLESTRINGS_TABLE_START] = sText_PkmnTraced,
    [STRINGID_STATSHARPLY - BATTLESTRINGS_TABLE_START] = sText_StatSharply,
    [STRINGID_STATROSE - BATTLESTRINGS_TABLE_START] = gText_StatRose,
    [STRINGID_STATHARSHLY - BATTLESTRINGS_TABLE_START] = sText_StatHarshly,
    [STRINGID_STATFELL - BATTLESTRINGS_TABLE_START] = sText_StatFell,
    [STRINGID_ATTACKERSSTATROSE - BATTLESTRINGS_TABLE_START] = sText_AttackersStatRose,
    [STRINGID_DEFENDERSSTATROSE - BATTLESTRINGS_TABLE_START] = gText_DefendersStatRose,
    [STRINGID_ATTACKERSSTATFELL - BATTLESTRINGS_TABLE_START] = sText_AttackersStatFell,
    [STRINGID_DEFENDERSSTATFELL - BATTLESTRINGS_TABLE_START] = sText_DefendersStatFell,
    [STRINGID_CRITICALHIT - BATTLESTRINGS_TABLE_START] = sText_CriticalHit,
    [STRINGID_ONEHITKO - BATTLESTRINGS_TABLE_START] = sText_OneHitKO,
    [STRINGID_123POOF - BATTLESTRINGS_TABLE_START] = sText_123Poof,
    [STRINGID_ANDELLIPSIS - BATTLESTRINGS_TABLE_START] = sText_AndEllipsis,
    [STRINGID_NOTVERYEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_NotVeryEffective,
    [STRINGID_SUPEREFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_SuperEffective,
    [STRINGID_GOTAWAYSAFELY - BATTLESTRINGS_TABLE_START] = sText_GotAwaySafely,
    [STRINGID_WILDPKMNFLED - BATTLESTRINGS_TABLE_START] = sText_WildPkmnFled,
    [STRINGID_NORUNNINGFROMTRAINERS - BATTLESTRINGS_TABLE_START] = sText_NoRunningFromTrainers,
    [STRINGID_CANTESCAPE - BATTLESTRINGS_TABLE_START] = sText_CantEscape,
    [STRINGID_DONTLEAVEBIRCH - BATTLESTRINGS_TABLE_START] = sText_DontLeaveBirch,
    [STRINGID_BUTNOTHINGHAPPENED - BATTLESTRINGS_TABLE_START] = sText_ButNothingHappened,
    [STRINGID_BUTITFAILED - BATTLESTRINGS_TABLE_START] = sText_ButItFailed,
    [STRINGID_ITHURTCONFUSION - BATTLESTRINGS_TABLE_START] = sText_ItHurtConfusion,
    [STRINGID_MIRRORMOVEFAILED - BATTLESTRINGS_TABLE_START] = sText_MirrorMoveFailed,
    [STRINGID_STARTEDTORAIN - BATTLESTRINGS_TABLE_START] = sText_StartedToRain,
    [STRINGID_DOWNPOURSTARTED - BATTLESTRINGS_TABLE_START] = sText_DownpourStarted,
    [STRINGID_RAINCONTINUES - BATTLESTRINGS_TABLE_START] = sText_RainContinues,
    [STRINGID_DOWNPOURCONTINUES - BATTLESTRINGS_TABLE_START] = sText_DownpourContinues,
    [STRINGID_RAINSTOPPED - BATTLESTRINGS_TABLE_START] = sText_RainStopped,
    [STRINGID_SANDSTORMBREWED - BATTLESTRINGS_TABLE_START] = sText_SandstormBrewed,
    [STRINGID_SANDSTORMRAGES - BATTLESTRINGS_TABLE_START] = sText_SandstormRages,
    [STRINGID_SANDSTORMSUBSIDED - BATTLESTRINGS_TABLE_START] = sText_SandstormSubsided,
    [STRINGID_SUNLIGHTGOTBRIGHT - BATTLESTRINGS_TABLE_START] = sText_SunlightGotBright,
    [STRINGID_SUNLIGHTSTRONG - BATTLESTRINGS_TABLE_START] = sText_SunlightStrong,
    [STRINGID_SUNLIGHTFADED - BATTLESTRINGS_TABLE_START] = sText_SunlightFaded,
    [STRINGID_STARTEDHAIL - BATTLESTRINGS_TABLE_START] = sText_StartedHail,
    [STRINGID_HAILCONTINUES - BATTLESTRINGS_TABLE_START] = sText_HailContinues,
    [STRINGID_HAILSTOPPED - BATTLESTRINGS_TABLE_START] = sText_HailStopped,
    [STRINGID_FAILEDTOSPITUP - BATTLESTRINGS_TABLE_START] = sText_FailedToSpitUp,
    [STRINGID_FAILEDTOSWALLOW - BATTLESTRINGS_TABLE_START] = sText_FailedToSwallow,
    [STRINGID_WINDBECAMEHEATWAVE - BATTLESTRINGS_TABLE_START] = sText_WindBecameHeatWave,
    [STRINGID_STATCHANGESGONE - BATTLESTRINGS_TABLE_START] = sText_StatChangesGone,
    [STRINGID_COINSSCATTERED - BATTLESTRINGS_TABLE_START] = sText_CoinsScattered,
    [STRINGID_TOOWEAKFORSUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_TooWeakForSubstitute,
    [STRINGID_SHAREDPAIN - BATTLESTRINGS_TABLE_START] = sText_SharedPain,
    [STRINGID_BELLCHIMED - BATTLESTRINGS_TABLE_START] = sText_BellChimed,
    [STRINGID_FAINTINTHREE - BATTLESTRINGS_TABLE_START] = sText_FaintInThree,
    [STRINGID_NOPPLEFT - BATTLESTRINGS_TABLE_START] = sText_NoPPLeft,
    [STRINGID_BUTNOPPLEFT - BATTLESTRINGS_TABLE_START] = sText_ButNoPPLeft,
    [STRINGID_PLAYERUSEDITEM - BATTLESTRINGS_TABLE_START] = sText_PlayerUsedItem,
    [STRINGID_WALLYUSEDITEM - BATTLESTRINGS_TABLE_START] = sText_WallyUsedItem,
    [STRINGID_TRAINERBLOCKEDBALL - BATTLESTRINGS_TABLE_START] = sText_TrainerBlockedBall,
    [STRINGID_DONTBEATHIEF - BATTLESTRINGS_TABLE_START] = sText_DontBeAThief,
    [STRINGID_ITDODGEDBALL - BATTLESTRINGS_TABLE_START] = sText_ItDodgedBall,
    [STRINGID_YOUMISSEDPKMN - BATTLESTRINGS_TABLE_START] = sText_YouMissedPkmn,
    [STRINGID_PKMNBROKEFREE - BATTLESTRINGS_TABLE_START] = sText_PkmnBrokeFree,
    [STRINGID_ITAPPEAREDCAUGHT - BATTLESTRINGS_TABLE_START] = sText_ItAppearedCaught,
    [STRINGID_AARGHALMOSTHADIT - BATTLESTRINGS_TABLE_START] = sText_AarghAlmostHadIt,
    [STRINGID_SHOOTSOCLOSE - BATTLESTRINGS_TABLE_START] = sText_ShootSoClose,
    [STRINGID_GOTCHAPKMNCAUGHTPLAYER - BATTLESTRINGS_TABLE_START] = sText_GotchaPkmnCaughtPlayer,
    [STRINGID_GOTCHAPKMNCAUGHTWALLY - BATTLESTRINGS_TABLE_START] = sText_GotchaPkmnCaughtWally,
    [STRINGID_GIVENICKNAMECAPTURED - BATTLESTRINGS_TABLE_START] = sText_GiveNicknameCaptured,
    [STRINGID_PKMNSENTTOPC - BATTLESTRINGS_TABLE_START] = sText_PkmnSentToPC,
    [STRINGID_PKMNDATAADDEDTODEX - BATTLESTRINGS_TABLE_START] = sText_PkmnDataAddedToDex,
    [STRINGID_ITISRAINING - BATTLESTRINGS_TABLE_START] = sText_ItIsRaining,
    [STRINGID_SANDSTORMISRAGING - BATTLESTRINGS_TABLE_START] = sText_SandstormIsRaging,
    [STRINGID_CANTESCAPE2 - BATTLESTRINGS_TABLE_START] = sText_CantEscape2,
    [STRINGID_PKMNIGNORESASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoresAsleep,
    [STRINGID_PKMNIGNOREDORDERS - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoredOrders,
    [STRINGID_PKMNBEGANTONAP - BATTLESTRINGS_TABLE_START] = sText_PkmnBeganToNap,
    [STRINGID_PKMNLOAFING - BATTLESTRINGS_TABLE_START] = sText_PkmnLoafing,
    [STRINGID_PKMNWONTOBEY - BATTLESTRINGS_TABLE_START] = sText_PkmnWontObey,
    [STRINGID_PKMNTURNEDAWAY - BATTLESTRINGS_TABLE_START] = sText_PkmnTurnedAway,
    [STRINGID_PKMNPRETENDNOTNOTICE - BATTLESTRINGS_TABLE_START] = sText_PkmnPretendNotNotice,
    [STRINGID_ENEMYABOUTTOSWITCHPKMN - BATTLESTRINGS_TABLE_START] = sText_EnemyAboutToSwitchPkmn,
    [STRINGID_CREPTCLOSER - BATTLESTRINGS_TABLE_START] = sText_CreptCloser,
    [STRINGID_CANTGETCLOSER - BATTLESTRINGS_TABLE_START] = sText_CantGetCloser,
    [STRINGID_PKMNWATCHINGCAREFULLY - BATTLESTRINGS_TABLE_START] = sText_PkmnWatchingCarefully,
    [STRINGID_PKMNCURIOUSABOUTX - BATTLESTRINGS_TABLE_START] = sText_PkmnCuriousAboutX,
    [STRINGID_PKMNENTHRALLEDBYX - BATTLESTRINGS_TABLE_START] = sText_PkmnEnthralledByX,
    [STRINGID_PKMNIGNOREDX - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoredX,
    [STRINGID_THREWPOKEBLOCKATPKMN - BATTLESTRINGS_TABLE_START] = sText_ThrewPokeblockAtPkmn,
    [STRINGID_OUTOFSAFARIBALLS - BATTLESTRINGS_TABLE_START] = sText_OutOfSafariBalls,
    [STRINGID_PKMNSITEMCUREDPARALYSIS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredParalysis,
    [STRINGID_PKMNSITEMCUREDPOISON - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredPoison,
    [STRINGID_PKMNSITEMHEALEDBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemHealedBurn,
    [STRINGID_PKMNSITEMDEFROSTEDIT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemDefrostedIt,
    [STRINGID_PKMNSITEMWOKEIT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemWokeIt,
    [STRINGID_PKMNSITEMSNAPPEDOUT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemSnappedOut,
    [STRINGID_PKMNSITEMCUREDPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredProblem,
    [STRINGID_PKMNSITEMRESTOREDHEALTH - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredHealth,
    [STRINGID_PKMNSITEMRESTOREDPP - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredPP,
    [STRINGID_PKMNSITEMRESTOREDSTATUS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredStatus,
    [STRINGID_PKMNSITEMRESTOREDHPALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredHPALittle,
    [STRINGID_ITEMALLOWSONLYYMOVE - BATTLESTRINGS_TABLE_START] = sText_ItemAllowsOnlyYMove,
    [STRINGID_PKMNHUNGONWITHX - BATTLESTRINGS_TABLE_START] = sText_PkmnHungOnWithX,
    [STRINGID_EMPTYSTRING3 - BATTLESTRINGS_TABLE_START] = gText_EmptyString3,
    [STRINGID_PKMNSXPREVENTSBURNS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsBurns,
    [STRINGID_PKMNSXBLOCKSY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXBlocksY,
    [STRINGID_PKMNSXRESTOREDHPALITTLE2 - BATTLESTRINGS_TABLE_START] = sText_PkmnsXRestoredHPALittle2,
    [STRINGID_PKMNSXWHIPPEDUPSANDSTORM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXWhippedUpSandstorm,
    [STRINGID_PKMNSXPREVENTSYLOSS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsYLoss,
    [STRINGID_PKMNSXINFATUATEDY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXInfatuatedY,
    [STRINGID_PKMNSXMADEYINEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeYIneffective,
    [STRINGID_PKMNSXCUREDYPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXCuredYProblem,
    [STRINGID_ITSUCKEDLIQUIDOOZE - BATTLESTRINGS_TABLE_START] = sText_ItSuckedLiquidOoze,
    [STRINGID_PKMNTRANSFORMED - BATTLESTRINGS_TABLE_START] = sText_PkmnTransformed,
    [STRINGID_ELECTRICITYWEAKENED - BATTLESTRINGS_TABLE_START] = sText_ElectricityWeakened,
    [STRINGID_FIREWEAKENED - BATTLESTRINGS_TABLE_START] = sText_FireWeakened,
    [STRINGID_PKMNHIDUNDERWATER - BATTLESTRINGS_TABLE_START] = sText_PkmnHidUnderwater,
    [STRINGID_PKMNSPRANGUP - BATTLESTRINGS_TABLE_START] = sText_PkmnSprangUp,
    [STRINGID_HMMOVESCANTBEFORGOTTEN - BATTLESTRINGS_TABLE_START] = sText_HMMovesCantBeForgotten,
    [STRINGID_XFOUNDONEY - BATTLESTRINGS_TABLE_START] = sText_XFoundOneY,
    [STRINGID_PLAYERDEFEATEDTRAINER1 - BATTLESTRINGS_TABLE_START] = sText_PlayerDefeatedLinkTrainerTrainer1,
    [STRINGID_SOOTHINGAROMA - BATTLESTRINGS_TABLE_START] = sText_SoothingAroma,
    [STRINGID_ITEMSCANTBEUSEDNOW - BATTLESTRINGS_TABLE_START] = sText_ItemsCantBeUsedNow,
    [STRINGID_FORXCOMMAYZ - BATTLESTRINGS_TABLE_START] = sText_ForXCommaYZ,
    [STRINGID_USINGITEMSTATOFPKMNROSE - BATTLESTRINGS_TABLE_START] = sText_UsingItemTheStatOfPkmnRose,
    [STRINGID_PKMNUSEDXTOGETPUMPED - BATTLESTRINGS_TABLE_START] = sText_PkmnUsedXToGetPumped,
    [STRINGID_PKMNSXMADEYUSELESS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeYUseless,
    [STRINGID_PKMNTRAPPEDBYSANDTOMB - BATTLESTRINGS_TABLE_START] = sText_PkmnTrappedBySandTomb,
    [STRINGID_EMPTYSTRING4 - BATTLESTRINGS_TABLE_START] = sText_EmptyString4,
    [STRINGID_ABOOSTED - BATTLESTRINGS_TABLE_START] = sText_ABoosted,
    [STRINGID_PKMNSXINTENSIFIEDSUN - BATTLESTRINGS_TABLE_START] = sText_PkmnsXIntensifiedSun,
    [STRINGID_PKMNMAKESGROUNDMISS - BATTLESTRINGS_TABLE_START] = sText_PkmnMakesGroundMiss,
    [STRINGID_YOUTHROWABALLNOWRIGHT - BATTLESTRINGS_TABLE_START] = sText_YouThrowABallNowRight,
    [STRINGID_PKMNSXTOOKATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnsXTookAttack,
    [STRINGID_PKMNCHOSEXASDESTINY - BATTLESTRINGS_TABLE_START] = sText_PkmnChoseXAsDestiny,
    [STRINGID_PKMNLOSTFOCUS - BATTLESTRINGS_TABLE_START] = sText_PkmnLostFocus,
    [STRINGID_USENEXTPKMN - BATTLESTRINGS_TABLE_START] = sText_UseNextPkmn,
    [STRINGID_PKMNFLEDUSINGITS - BATTLESTRINGS_TABLE_START] = sText_PkmnFledUsingIts,
    [STRINGID_PKMNFLEDUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnFledUsing,
    [STRINGID_PKMNWASDRAGGEDOUT - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDraggedOut,
    [STRINGID_PREVENTEDFROMWORKING - BATTLESTRINGS_TABLE_START] = sText_PreventedFromWorking,
    [STRINGID_PKMNSITEMNORMALIZEDSTATUS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemNormalizedStatus,
    [STRINGID_TRAINER1USEDITEM - BATTLESTRINGS_TABLE_START] = sText_Trainer1UsedItem,
    [STRINGID_BOXISFULL - BATTLESTRINGS_TABLE_START] = sText_BoxIsFull,
    [STRINGID_PKMNAVOIDEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnAvoidedAttack,
    [STRINGID_PKMNSXMADEITINEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeItIneffective,
    [STRINGID_PKMNSXPREVENTSFLINCHING - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsFlinching,
    [STRINGID_PKMNALREADYHASBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyHasBurn,
    [STRINGID_STATSWONTDECREASE2 - BATTLESTRINGS_TABLE_START] = sText_StatsWontDecrease2,
    [STRINGID_PKMNSXBLOCKSY2 - BATTLESTRINGS_TABLE_START] = sText_PkmnsXBlocksY2,
    [STRINGID_PKMNSXWOREOFF - BATTLESTRINGS_TABLE_START] = sText_PkmnsXWoreOff,
    [STRINGID_PKMNRAISEDDEFALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedDefALittle,
    [STRINGID_PKMNRAISEDSPDEFALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpDefALittle,
    [STRINGID_THEWALLSHATTERED - BATTLESTRINGS_TABLE_START] = sText_TheWallShattered,
    [STRINGID_PKMNSXPREVENTSYSZ - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsYsZ,
    [STRINGID_PKMNSXCUREDITSYPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXCuredItsYProblem,
    [STRINGID_ATTACKERCANTESCAPE - BATTLESTRINGS_TABLE_START] = sText_AttackerCantEscape,
    [STRINGID_PKMNOBTAINEDX - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedX,
    [STRINGID_PKMNOBTAINEDX2 - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedX2,
    [STRINGID_PKMNOBTAINEDXYOBTAINEDZ - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedXYObtainedZ,
    [STRINGID_BUTNOEFFECT - BATTLESTRINGS_TABLE_START] = sText_ButNoEffect,
    [STRINGID_PKMNSXHADNOEFFECTONY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXHadNoEffectOnY,
    [STRINGID_TWOENEMIESDEFEATED - BATTLESTRINGS_TABLE_START] = sText_TwoInGameTrainersDefeated,
    [STRINGID_TRAINER2LOSETEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer2LoseText,
    [STRINGID_PKMNINCAPABLEOFPOWER - BATTLESTRINGS_TABLE_START] = sText_PkmnIncapableOfPower,
    [STRINGID_GLINTAPPEARSINEYE - BATTLESTRINGS_TABLE_START] = sText_GlintAppearsInEye,
    [STRINGID_PKMNGETTINGINTOPOSITION - BATTLESTRINGS_TABLE_START] = sText_PkmnGettingIntoPosition,
    [STRINGID_PKMNBEGANGROWLINGDEEPLY - BATTLESTRINGS_TABLE_START] = sText_PkmnBeganGrowlingDeeply,
    [STRINGID_PKMNEAGERFORMORE - BATTLESTRINGS_TABLE_START] = sText_PkmnEagerForMore,
    [STRINGID_DEFEATEDOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_DefeatedOpponentByReferee,
    [STRINGID_LOSTTOOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_LostToOpponentByReferee,
    [STRINGID_TIEDOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_TiedOpponentByReferee,
    [STRINGID_QUESTIONFORFEITMATCH - BATTLESTRINGS_TABLE_START] = sText_QuestionForfeitMatch,
    [STRINGID_FORFEITEDMATCH - BATTLESTRINGS_TABLE_START] = sText_ForfeitedMatch,
    [STRINGID_PKMNTRANSFERREDSOMEONESPC - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredSomeonesPC,
    [STRINGID_PKMNTRANSFERREDBillSPC - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredBillsPC,
    [STRINGID_PKMNBOXSOMEONESPCFULL - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredSomeonesPCBoxFull,
    [STRINGID_PKMNBOXBillSPCFULL - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredBillsPCBoxFull,
    [STRINGID_TRAINER1WINTEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer1WinText,
    [STRINGID_TRAINER2WINTEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer2WinText,
    [STRINGID_ONETYPECAPTUREBLOCKED - BATTLESTRINGS_TABLE_START] = gText_OneTypeChallengeCantThrowPokeBall,
    [STRINGID_NUZLOCKECAPTUREBLOCKED - BATTLESTRINGS_TABLE_START] = gText_NuzlockeCantThrowPokeBallRoute,
    [STRINGID_SPECIESCLAUSECAPTUREBLOCKED - BATTLESTRINGS_TABLE_START] = gText_NuzlockeCantThrowPokeBallSpeciesClause,
    [STRINGID_SAMESPECIESCAPTUREBLOCKED - BATTLESTRINGS_TABLE_START] = gText_NuzlockeCantThrowPokeBallAlreadyCaught,
    [STRINGID_PKMNGAINEDEXPALL - BATTLESTRINGS_TABLE_START] = sText_PkmnGainedEXPAll,
    [STRINGID_BAGISFULL - BATTLESTRINGS_TABLE_START] = sText_BagIsFull,
    [STRINGID_PKMNDROPPEDITEM - BATTLESTRINGS_TABLE_START] = sText_PkmnDroppedItem,
};

const u16 gMissStringIds[] =
{
    [B_MSG_MISSED]      = STRINGID_ATTACKMISSED,
    [B_MSG_PROTECTED]   = STRINGID_PKMNPROTECTEDITSELF,
    [B_MSG_AVOIDED_ATK] = STRINGID_PKMNAVOIDEDATTACK,
    [B_MSG_AVOIDED_DMG] = STRINGID_AVOIDEDDAMAGE,
    [B_MSG_GROUND_MISS] = STRINGID_PKMNMAKESGROUNDMISS
};

const u16 gNoEscapeStringIds[] =
{
    [B_MSG_CANT_ESCAPE]          = STRINGID_CANTESCAPE,
    [B_MSG_DONT_LEAVE_BIRCH]     = STRINGID_DONTLEAVEBIRCH,
    [B_MSG_PREVENTS_ESCAPE]      = STRINGID_PREVENTSESCAPE,
    [B_MSG_CANT_ESCAPE_2]        = STRINGID_CANTESCAPE2,
    [B_MSG_ATTACKER_CANT_ESCAPE] = STRINGID_ATTACKERCANTESCAPE
};

const u16 gMoveWeatherChangeStringIds[] =
{
    [B_MSG_STARTED_RAIN]      = STRINGID_STARTEDTORAIN,
    [B_MSG_STARTED_DOWNPOUR]  = STRINGID_DOWNPOURSTARTED, // Unused
    [B_MSG_WEATHER_FAILED]    = STRINGID_BUTITFAILED,
    [B_MSG_STARTED_SANDSTORM] = STRINGID_SANDSTORMBREWED,
    [B_MSG_STARTED_SUNLIGHT]  = STRINGID_SUNLIGHTGOTBRIGHT,
    [B_MSG_STARTED_HAIL]      = STRINGID_STARTEDHAIL,
};

const u16 gSandStormHailContinuesStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMRAGES,
    [B_MSG_HAIL]      = STRINGID_HAILCONTINUES
};

const u16 gSandStormHailDmgStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_PKMNBUFFETEDBYSANDSTORM,
    [B_MSG_HAIL]      = STRINGID_PKMNPELTEDBYHAIL
};

const u16 gSandStormHailEndStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMSUBSIDED,
    [B_MSG_HAIL]      = STRINGID_HAILSTOPPED
};

const u16 gRainContinuesStringIds[] =
{
    [B_MSG_RAIN_CONTINUES]     = STRINGID_RAINCONTINUES,
    [B_MSG_DOWNPOUR_CONTINUES] = STRINGID_DOWNPOURCONTINUES,
    [B_MSG_RAIN_STOPPED]       = STRINGID_RAINSTOPPED
};

const u16 gProtectLikeUsedStringIds[] =
{
    [B_MSG_PROTECTED_ITSELF] = STRINGID_PKMNPROTECTEDITSELF2,
    [B_MSG_BRACED_ITSELF]    = STRINGID_PKMNBRACEDITSELF,
    [B_MSG_PROTECT_FAILED]   = STRINGID_BUTITFAILED,
};

const u16 gReflectLightScreenSafeguardStringIds[] =
{
    [B_MSG_SIDE_STATUS_FAILED]     = STRINGID_BUTITFAILED,
    [B_MSG_SET_REFLECT_SINGLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_REFLECT_DOUBLE]     = STRINGID_PKMNRAISEDDEFALITTLE,
    [B_MSG_SET_LIGHTSCREEN_SINGLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_LIGHTSCREEN_DOUBLE] = STRINGID_PKMNRAISEDSPDEFALITTLE,
    [B_MSG_SET_SAFEGUARD]          = STRINGID_PKMNCOVEREDBYVEIL,
};

const u16 gLeechSeedStringIds[] =
{
    [B_MSG_LEECH_SEED_SET]   = STRINGID_PKMNSEEDED,
    [B_MSG_LEECH_SEED_MISS]  = STRINGID_PKMNEVADEDATTACK,
    [B_MSG_LEECH_SEED_FAIL]  = STRINGID_ITDOESNTAFFECT,
    [B_MSG_LEECH_SEED_DRAIN] = STRINGID_PKMNSAPPEDBYLEECHSEED,
    [B_MSG_LEECH_SEED_OOZE]  = STRINGID_ITSUCKEDLIQUIDOOZE,
};

const u16 gRestUsedStringIds[] =
{
    [B_MSG_REST]          = STRINGID_PKMNWENTTOSLEEP,
    [B_MSG_REST_STATUSED] = STRINGID_PKMNSLEPTHEALTHY
};

const u16 gUproarOverTurnStringIds[] =
{
    [B_MSG_UPROAR_CONTINUES] = STRINGID_PKMNMAKINGUPROAR,
    [B_MSG_UPROAR_ENDS]      = STRINGID_PKMNCALMEDDOWN
};

const u16 gStockpileUsedStringIds[] =
{
    [B_MSG_STOCKPILED]     = STRINGID_PKMNSTOCKPILED,
    [B_MSG_CANT_STOCKPILE] = STRINGID_PKMNCANTSTOCKPILE,
};

const u16 gWokeUpStringIds[] =
{
    [B_MSG_WOKE_UP]        = STRINGID_PKMNWOKEUP,
    [B_MSG_WOKE_UP_UPROAR] = STRINGID_PKMNWOKEUPINUPROAR
};

const u16 gSwallowFailStringIds[] =
{
    [B_MSG_SWALLOW_FAILED]  = STRINGID_FAILEDTOSWALLOW,
    [B_MSG_SWALLOW_FULL_HP] = STRINGID_PKMNHPFULL
};

const u16 gUproarAwakeStringIds[] =
{
    [B_MSG_CANT_SLEEP_UPROAR]  = STRINGID_PKMNCANTSLEEPINUPROAR2,
    [B_MSG_UPROAR_KEPT_AWAKE]  = STRINGID_UPROARKEPTPKMNAWAKE,
    [B_MSG_STAYED_AWAKE_USING] = STRINGID_PKMNSTAYEDAWAKEUSING,
};

const u16 gStatUpStringIds[] =
{
    [B_MSG_ATTACKER_STAT_ROSE] = STRINGID_ATTACKERSSTATROSE,
    [B_MSG_DEFENDER_STAT_ROSE] = STRINGID_DEFENDERSSTATROSE,
    [B_MSG_STAT_WONT_INCREASE] = STRINGID_STATSWONTINCREASE,
    [B_MSG_STAT_ROSE_EMPTY]    = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_ROSE_ITEM]     = STRINGID_USINGITEMSTATOFPKMNROSE,
    [B_MSG_USED_DIRE_HIT]      = STRINGID_PKMNUSEDXTOGETPUMPED,
};

const u16 gStatDownStringIds[] =
{
    [B_MSG_ATTACKER_STAT_FELL] = STRINGID_ATTACKERSSTATFELL,
    [B_MSG_DEFENDER_STAT_FELL] = STRINGID_DEFENDERSSTATFELL,
    [B_MSG_STAT_WONT_DECREASE] = STRINGID_STATSWONTDECREASE,
    [B_MSG_STAT_FELL_EMPTY]    = STRINGID_EMPTYSTRING3,
};

// Index read from sTWOTURN_STRINGID
const u16 gFirstTurnOfTwoStringIds[] =
{
    [B_MSG_TURN1_RAZOR_WIND] = STRINGID_PKMNWHIPPEDWHIRLWIND,
    [B_MSG_TURN1_SOLAR_BEAM] = STRINGID_PKMNTOOKSUNLIGHT,
    [B_MSG_TURN1_SKULL_BASH] = STRINGID_PKMNLOWEREDHEAD,
    [B_MSG_TURN1_SKY_ATTACK] = STRINGID_PKMNISGLOWING,
    [B_MSG_TURN1_FLY]        = STRINGID_PKMNFLEWHIGH,
    [B_MSG_TURN1_DIG]        = STRINGID_PKMNDUGHOLE,
    [B_MSG_TURN1_DIVE]       = STRINGID_PKMNHIDUNDERWATER,
    [B_MSG_TURN1_BOUNCE]     = STRINGID_PKMNSPRANGUP,
};

// Index copied from move's index in gTrappingMoves
const u16 gWrappedStringIds[NUM_TRAPPING_MOVES] =
{
    STRINGID_PKMNSQUEEZEDBYBIND,   // MOVE_BIND
    STRINGID_PKMNWRAPPEDBY,        // MOVE_WRAP
    STRINGID_PKMNTRAPPEDINVORTEX,  // MOVE_FIRE_SPIN
    STRINGID_PKMNCLAMPED,          // MOVE_CLAMP
    STRINGID_PKMNTRAPPEDINVORTEX,  // MOVE_WHIRLPOOL
    STRINGID_PKMNTRAPPEDBYSANDTOMB // MOVE_SAND_TOMB
};

const u16 gMistUsedStringIds[] =
{
    [B_MSG_SET_MIST]    = STRINGID_PKMNSHROUDEDINMIST,
    [B_MSG_MIST_FAILED] = STRINGID_BUTITFAILED
};

const u16 gFocusEnergyUsedStringIds[] =
{
    [B_MSG_GETTING_PUMPED]      = STRINGID_PKMNGETTINGPUMPED,
    [B_MSG_FOCUS_ENERGY_FAILED] = STRINGID_BUTITFAILED
};

const u16 gTransformUsedStringIds[] =
{
    [B_MSG_TRANSFORMED]      = STRINGID_PKMNTRANSFORMEDINTO,
    [B_MSG_TRANSFORM_FAILED] = STRINGID_BUTITFAILED
};

const u16 gSubstituteUsedStringIds[] =
{
    [B_MSG_SET_SUBSTITUTE]    = STRINGID_PKMNMADESUBSTITUTE,
    [B_MSG_SUBSTITUTE_FAILED] = STRINGID_TOOWEAKFORSUBSTITUTE
};

const u16 gGotPoisonedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPOISONED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNPOISONEDBY
};

const u16 gGotParalyzedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPARALYZED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNWASPARALYZEDBY
};

const u16 gFellAsleepStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLASLEEP,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNMADESLEEP,
};

const u16 gGotBurnedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASBURNED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNBURNEDBY
};

const u16 gGotFrozenStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASFROZEN,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNFROZENBY
};

const u16 gGotDefrostedStringIds[] =
{
    [B_MSG_DEFROSTED]         = STRINGID_PKMNWASDEFROSTED2,
    [B_MSG_DEFROSTED_BY_MOVE] = STRINGID_PKMNWASDEFROSTEDBY
};

const u16 gKOFailedStringIds[] =
{
    [B_MSG_KO_MISS]       = STRINGID_ATTACKMISSED,
    [B_MSG_KO_UNAFFECTED] = STRINGID_PKMNUNAFFECTED
};

const u16 gAttractUsedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLINLOVE,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNSXINFATUATEDY
};

const u16 gAbsorbDrainStringIds[] =
{
    [B_MSG_ABSORB]      = STRINGID_PKMNENERGYDRAINED,
    [B_MSG_ABSORB_OOZE] = STRINGID_ITSUCKEDLIQUIDOOZE
};

const u16 gSportsUsedStringIds[] =
{
    [B_MSG_WEAKEN_ELECTRIC] = STRINGID_ELECTRICITYWEAKENED,
    [B_MSG_WEAKEN_FIRE]     = STRINGID_FIREWEAKENED
};

const u16 gPartyStatusHealStringIds[] =
{
    [B_MSG_BELL]                     = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_ATTACKER] = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_PARTNER]  = STRINGID_BELLCHIMED,
    [B_MSG_BELL_BOTH_SOUNDPROOF]     = STRINGID_BELLCHIMED,
    [B_MSG_SOOTHING_AROMA]           = STRINGID_SOOTHINGAROMA
};

const u16 gFutureMoveUsedStringIds[] =
{
    [B_MSG_FUTURE_SIGHT] = STRINGID_PKMNFORESAWATTACK,
    [B_MSG_DOOM_DESIRE]  = STRINGID_PKMNCHOSEXASDESTINY
};

const u16 gBallEscapeStringIds[] =
{
    [BALL_NO_SHAKES]     = STRINGID_PKMNBROKEFREE,
    [BALL_1_SHAKE]       = STRINGID_ITAPPEAREDCAUGHT,
    [BALL_2_SHAKES]      = STRINGID_AARGHALMOSTHADIT,
    [BALL_3_SHAKES_FAIL] = STRINGID_SHOOTSOCLOSE
};

// Overworld weathers that don't have an associated battle weather default to "It is raining."
const u16 gWeatherStartsStringIds[] =
{
    [WEATHER_NONE]               = STRINGID_ITISRAINING,
    [WEATHER_SUNNY_CLOUDS]       = STRINGID_ITISRAINING,
    [WEATHER_SUNNY]              = STRINGID_ITISRAINING,
    [WEATHER_RAIN]               = STRINGID_ITISRAINING,
    [WEATHER_SNOW]               = STRINGID_STARTEDHAIL,
    [WEATHER_RAIN_THUNDERSTORM]  = STRINGID_ITISRAINING,
    [WEATHER_FOG_HORIZONTAL]     = STRINGID_ITISRAINING,
    [WEATHER_VOLCANIC_ASH]       = STRINGID_ITISRAINING,
    [WEATHER_SANDSTORM]          = STRINGID_SANDSTORMISRAGING,
    [WEATHER_FOG_DIAGONAL]       = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER]         = STRINGID_ITISRAINING,
    [WEATHER_SHADE]              = STRINGID_ITISRAINING,
    [WEATHER_DROUGHT]            = STRINGID_SUNLIGHTSTRONG,
    [WEATHER_DOWNPOUR]           = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER_BUBBLES] = STRINGID_ITISRAINING,
    [WEATHER_ABNORMAL]           = STRINGID_ITISRAINING
};

const u16 gInobedientStringIds[] =
{
    [B_MSG_LOAFING]            = STRINGID_PKMNLOAFING,
    [B_MSG_WONT_OBEY]          = STRINGID_PKMNWONTOBEY,
    [B_MSG_TURNED_AWAY]        = STRINGID_PKMNTURNEDAWAY,
    [B_MSG_PRETEND_NOT_NOTICE] = STRINGID_PKMNPRETENDNOTNOTICE,
    [B_MSG_INCAPABLE_OF_POWER] = STRINGID_PKMNINCAPABLEOFPOWER
};

const u16 gSafariGetNearStringIds[] =
{
    [B_MSG_CREPT_CLOSER]    = STRINGID_CREPTCLOSER,
    [B_MSG_CANT_GET_CLOSER] = STRINGID_CANTGETCLOSER
};

const u16 gSafariPokeblockResultStringIds[] =
{
    [B_MSG_MON_CURIOUS]    = STRINGID_PKMNCURIOUSABOUTX,
    [B_MSG_MON_ENTHRALLED] = STRINGID_PKMNENTHRALLEDBYX,
    [B_MSG_MON_IGNORED]    = STRINGID_PKMNIGNOREDX
};

const u16 gTrainerItemCuredStatusStringIds[] =
{
    [AI_HEAL_CONFUSION] = STRINGID_PKMNSITEMSNAPPEDOUT,
    [AI_HEAL_PARALYSIS] = STRINGID_PKMNSITEMCUREDPARALYSIS,
    [AI_HEAL_FREEZE]    = STRINGID_PKMNSITEMDEFROSTEDIT,
    [AI_HEAL_BURN]      = STRINGID_PKMNSITEMHEALEDBURN,
    [AI_HEAL_POISON]    = STRINGID_PKMNSITEMCUREDPOISON,
    [AI_HEAL_SLEEP]     = STRINGID_PKMNSITEMWOKEIT
};

const u16 gBerryEffectStringIds[] =
{
    [B_MSG_CURED_PROBLEM]     = STRINGID_PKMNSITEMCUREDPROBLEM,
    [B_MSG_NORMALIZED_STATUS] = STRINGID_PKMNSITEMNORMALIZEDSTATUS
};

const u16 gBRNPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNSXPREVENTSBURNS,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gPRLZPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPARALYSISWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gPSNPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPOISONINGWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gItemSwapStringIds[] =
{
    [B_MSG_ITEM_SWAP_TAKEN] = STRINGID_PKMNOBTAINEDX,
    [B_MSG_ITEM_SWAP_GIVEN] = STRINGID_PKMNOBTAINEDX2,
    [B_MSG_ITEM_SWAP_BOTH]  = STRINGID_PKMNOBTAINEDXYOBTAINEDZ
};

const u16 gFlashFireStringIds[] =
{
    [B_MSG_FLASH_FIRE_BOOST]    = STRINGID_PKMNRAISEDFIREPOWERWITH,
    [B_MSG_FLASH_FIRE_NO_BOOST] = STRINGID_PKMNSXMADEYINEFFECTIVE
};

const u16 gCaughtMonStringIds[] =
{
    [B_MSG_SENT_SOMEONES_PC]  = STRINGID_PKMNTRANSFERREDSOMEONESPC,
    [B_MSG_SENT_BillS_PC]  = STRINGID_PKMNTRANSFERREDBillSPC,
    [B_MSG_SOMEONES_BOX_FULL] = STRINGID_PKMNBOXSOMEONESPCFULL,
    [B_MSG_BillS_BOX_FULL] = STRINGID_PKMNBOXBillSPCFULL,
};

const u16 gTrappingMoves[NUM_TRAPPING_MOVES + 1] =
{
    MOVE_BIND,
    MOVE_WRAP,
    MOVE_FIRE_SPIN,
    MOVE_CLAMP,
    MOVE_WHIRLPOOL,
    MOVE_SAND_TOMB,
    0xFFFF // Never read
};

const u16 gItemDroppedStringIds[] =
{
    [B_MSG_ITEM_DROPPED] = STRINGID_PKMNDROPPEDITEM,
    [B_MSG_BAG_IS_FULL] = STRINGID_BAGISFULL,
};

const u8 gText_PkmnIsEvolving[] = _("{JPN}おや!?\n{STR_VAR_1}の ようすが......!");
const u8 gText_CongratsPkmnEvolved[] = _("{JPN}おめでとう! {STR_VAR_1}は\n{STR_VAR_2}に しんかした!{WAIT_SE}\p");
const u8 gText_PkmnStoppedEvolving[] = _("{JPN}あれ? {STR_VAR_1}の\nしんかが とまった!\p");
const u8 gText_EllipsisQuestionMark[] = _("{JPN}.........?\p");
const u8 gText_WhatWillPkmnDo[] = _("{JPN} {B_ACTIVE_NAME_WITH_PREFIX}は\nどうする?");
const u8 gText_WhatWillPkmnDo2[] = _("{JPN} {B_PLAYER_NAME}は\nどうする?");
const u8 gText_WhatWillWallyDo[] = _("{JPN}ミツルは\nどうする?");
const u8 gText_LinkStandby[] = _("{JPN}{PAUSE 16}つうしんたいきちゅう...");
const u8 gText_BattleMenu[] = _("{JPN}たたかう{CLEAR_TO 56}バッグ\nポケモン{CLEAR_TO 56}にげる");
const u8 gText_SafariZoneMenu[] = _("{JPN}ボール{CLEAR_TO 56}{POKEBLOCK}\nちかづく{CLEAR_TO 56}にげる");
const u8 gText_MoveInterfacePP[] = _("PP ");
const u8 gText_MoveInterfaceType[] = _("{JPN}タイプ/");
const u8 gText_MoveInterfacePpType[] = _("{JPN}{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}PP\nタイプ/");
const u8 gText_MoveInterfaceDynamicColors[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_WhichMoveToForget4[] = _("{JPN}{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}どの わざを\nわすれさせますか?");
const u8 gText_BattleYesNoChoice[] = _("{JPN}{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}はい\nいいえ");
const u8 gText_BattleSwitchWhich[] = _("{JPN}{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}だれと\nいれかえる?");
const u8 gText_BattleSwitchWhich2[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_BattleSwitchWhich3[] = _("{UP_ARROW}");
const u8 gText_BattleSwitchWhich4[] = _("{ESCAPE 4}");
const u8 gText_BattleSwitchWhich5[] = _("-");

static const u8 sText_HP[] = _("HP");
static const u8 sText_Attack[] = _("{JPN}こうげき");
static const u8 sText_Defense[] = _("{JPN}ぼうぎょ");
static const u8 sText_SpAtk[] = _("{JPN}とくこう");
static const u8 sText_SpDef[] = _("{JPN}とくぼう");

// Unused
static const u8 * const sStatNamesTable2[] =
{
    sText_HP, sText_SpAtk, sText_Attack,
    sText_SpDef, sText_Defense, sText_Speed
};

const u8 gText_SafariBalls[] = _("{JPN}{HIGHLIGHT DARK_GRAY}サファリボール");
const u8 gText_SafariBallLeft[] = _("{JPN}{HIGHLIGHT DARK_GRAY}のこり $" "{HIGHLIGHT DARK_GRAY}");
const u8 gText_Sleep[] = _("{JPN}ねむり");
const u8 gText_Poison[] = _("{JPN}どく");
const u8 gText_Burn[] = _("{JPN}やけど");
const u8 gText_Paralysis[] = _("{JPN}まひ");
const u8 gText_Ice[] = _("{JPN}こおり");
const u8 gText_Confusion[] = _("{JPN}こんらん");
const u8 gText_Love[] = _("{JPN}メロメロ");
const u8 gText_SpaceAndSpace[] = _("{JPN}と ");
const u8 gText_CommaSpace[] = _(", ");
const u8 gText_Space2[] = _(" ");
const u8 gText_LineBreak[] = _("\l");
const u8 gText_NewLine[] = _("\n");
const u8 gText_Are[] = _("{JPN}は");
const u8 gText_Are2[] = _("{JPN}は");
const u8 gText_BadEgg[] = _("{JPN}ダメタマゴ");
const u8 gText_BattleWallyName[] = _("{JPN}ミツル");
const u8 gText_Win[] = _("{JPN}{HIGHLIGHT TRANSPARENT}かち");
const u8 gText_Loss[] = _("{JPN}{HIGHLIGHT TRANSPARENT}まけ");
const u8 gText_Draw[] = _("{JPN}{HIGHLIGHT TRANSPARENT}ひきわけ");
static const u8 sText_SpaceIs[] = _("{JPN} は");
static const u8 sText_ApostropheS[] = _("{JPN}の");

// For displaying names of invalid moves.
// This is large enough that the text for TYPE_ELECTRIC will exceed TEXT_BUFF_ARRAY_COUNT.
static const u8 sATypeMove_Table[NUMBER_OF_MON_TYPES][17] =
{
    [TYPE_NORMAL]   = _("{JPN}ノーマルわざ"),
    [TYPE_FIGHTING] = _("{JPN}かくとうわざ"),
    [TYPE_FLYING]   = _("{JPN}ひこうわざ"),
    [TYPE_POISON]   = _("{JPN}どくわざ"),
    [TYPE_GROUND]   = _("{JPN}じめんわざ"),
    [TYPE_ROCK]     = _("{JPN}いわわざ"),
    [TYPE_BUG]      = _("{JPN}むしわざ"),
    [TYPE_GHOST]    = _("{JPN}ゴーストわざ"),
    [TYPE_STEEL]    = _("{JPN}はがねわざ"),
    [TYPE_MYSTERY]  = _("{JPN}???わざ"),
    [TYPE_FIRE]     = _("{JPN}ほのおわざ"),
    [TYPE_WATER]    = _("{JPN}みずわざ"),
    [TYPE_GRASS]    = _("{JPN}くさわざ"),
    [TYPE_ELECTRIC] = _("{JPN}でんきわざ"),
    [TYPE_PSYCHIC]  = _("{JPN}エスパーわざ"),
    [TYPE_ICE]      = _("{JPN}こおりわざ"),
    [TYPE_DRAGON]   = _("{JPN}ドラゴンわざ"),
    [TYPE_DARK]     = _("{JPN}あくわざ")
};

const u8 gText_BattleTourney[] = _("{JPN}バトルトーナメント");
static const u8 sText_Round1[] = _("{JPN}1かいせん");
static const u8 sText_Round2[] = _("{JPN}2かいせん");
static const u8 sText_Semifinal[] = _("{JPN}じゅんけっしょう");
static const u8 sText_Final[] = _("{JPN}けっしょう");

const u8 *const gRoundsStringTable[DOME_ROUNDS_COUNT] =
{
    [DOME_ROUND1]    = sText_Round1,
    [DOME_ROUND2]    = sText_Round2,
    [DOME_SEMIFINAL] = sText_Semifinal,
    [DOME_FINAL]     = sText_Final
};

const u8 gText_TheGreatNewHope[] = _("{JPN}きたいの しんせい!\p");
const u8 gText_WillChampionshipDreamComeTrue[] = _("{JPN}ゆうしょうの ゆめは かなうか?!\p");
const u8 gText_AFormerChampion[] = _("{JPN}もと チャンピオン!\p");
const u8 gText_ThePreviousChampion[] = _("{JPN}ぜんかい チャンピオン!\p");
const u8 gText_TheUnbeatenChampion[] = _("{JPN}むてきの チャンピオン!\p");
const u8 gText_PlayerMon1Name[] = _("{B_PLAYER_MON1_NAME}");
const u8 gText_Vs[] = _("VS");
const u8 gText_OpponentMon1Name[] = _("{B_OPPONENT_MON1_NAME}");
const u8 gText_Mind[] = _("{JPN}きもち");
const u8 gText_Skill[] = _("{JPN}わざ");
const u8 gText_Body[] = _("{JPN}からだ");
const u8 gText_Judgment[] = _("{JPN}{B_BUFF1}{CLEAR 13}はんてい{CLEAR 13}{B_BUFF2}");
static const u8 sText_TwoTrainersSentPkmn[] = _("{JPN}{B_TRAINER1_CLASS} {B_TRAINER1_NAME}は\n{B_OPPONENT_MON1_NAME}を くりだした!\p{B_TRAINER2_CLASS} {B_TRAINER2_NAME}は\n{B_OPPONENT_MON2_NAME}を くりだした!");
static const u8 sText_Trainer2SentOutPkmn[] = _("{JPN}{B_TRAINER2_CLASS} {B_TRAINER2_NAME}は\n{B_BUFF1}を くりだした!");
static const u8 sText_TwoTrainersWantToBattle[] = _("{JPN}{B_TRAINER1_CLASS} {B_TRAINER1_NAME}と\n{B_TRAINER2_CLASS} {B_TRAINER2_NAME}が\lしょうぶを しかけてきた!\p");
static const u8 sText_InGamePartnerSentOutZGoN[] = _("{JPN}{B_PARTNER_CLASS} {B_PARTNER_NAME}は\n{B_PLAYER_MON2_NAME}を くりだした!\lいけっ! {B_PLAYER_MON1_NAME}!");
static const u8 sText_TwoInGameTrainersDefeated[] = _("{JPN}{B_TRAINER1_CLASS} {B_TRAINER1_NAME}と\n{B_TRAINER2_CLASS} {B_TRAINER2_NAME}に\lかった!\p");
static const u8 sText_Trainer2LoseText[] = _("{B_TRAINER2_LOSE_TEXT}");
static const u8 sText_PkmnIncapableOfPower[] = _("{JPN}{B_ATK_NAME_WITH_PREFIX}は ちからを\nだしきれない ようだ!");
static const u8 sText_GlintAppearsInEye[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}の めが\nキラリと ひかった!");
static const u8 sText_PkmnGettingIntoPosition[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は\nたいせいを とっている!");
static const u8 sText_PkmnBeganGrowlingDeeply[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は\nふかく うなりはじめた!");
static const u8 sText_PkmnEagerForMore[] = _("{JPN}{B_SCR_ACTIVE_NAME_WITH_PREFIX}は\nまだまだ やるきだ!");

const u16 gBattlePalaceFlavorTextTable[] =
{
    [B_MSG_GLINT_IN_EYE]   = STRINGID_GLINTAPPEARSINEYE,
    [B_MSG_GETTING_IN_POS] = STRINGID_PKMNGETTINGINTOPOSITION,
    [B_MSG_GROWL_DEEPLY]   = STRINGID_PKMNBEGANGROWLINGDEEPLY,
    [B_MSG_EAGER_FOR_MORE] = STRINGID_PKMNEAGERFORMORE,
};

static const u8 sText_RefIfNothingIsDecided[] = _("{JPN}しんぱん- 3ターンいないに\nけっちゃくが つかなければ はんていだ!");
static const u8 sText_RefThatsIt[] = _("{JPN}しんぱん- そこまで!\nはんていに うつります!");
static const u8 sText_RefJudgeMind[] = _("{JPN}しんぱん- はんてい1 きもち!\nいちばん きあいの はいった ポケモン!\p");
static const u8 sText_RefJudgeSkill[] = _("{JPN}しんぱん- はんてい2 わざ!\nいちばん うまく わざを つかった ポケモン!\p");
static const u8 sText_RefJudgeBody[] = _("{JPN}しんぱん- はんてい3 からだ!\nいちばん たいりょくの ある ポケモン!\p");
static const u8 sText_RefPlayerWon[] = _("{JPN}しんぱん- はんてい {B_BUFF1}たい{B_BUFF2}!\nかちは {B_PLAYER_NAME}の {B_PLAYER_MON1_NAME}!\p");
static const u8 sText_RefOpponentWon[] = _("{JPN}しんぱん- はんてい {B_BUFF1}たい{B_BUFF2}!\nかちは {B_TRAINER1_NAME}の {B_OPPONENT_MON1_NAME}!\p");
static const u8 sText_RefDraw[] = _("{JPN}しんぱん- はんてい 3たい3!\nひきわけです!\p");
static const u8 sText_DefeatedOpponentByReferee[] = _("{JPN}{B_PLAYER_MON1_NAME}は はんていで\nあいての {B_OPPONENT_MON1_NAME}に かった!");
static const u8 sText_LostToOpponentByReferee[] = _("{JPN}{B_PLAYER_MON1_NAME}は はんていで\nあいての {B_OPPONENT_MON1_NAME}に まけた!");
static const u8 sText_TiedOpponentByReferee[] = _("{JPN}{B_PLAYER_MON1_NAME}は はんていで\nあいての {B_OPPONENT_MON1_NAME}と ひきわけた!");
static const u8 sText_RefCommenceBattle[] = _("{JPN}しんぱん- {B_PLAYER_MON1_NAME} VS {B_OPPONENT_MON1_NAME}!\nしあい かいし!");

const u8 * const gRefereeStringsTable[] =
{
    [B_MSG_REF_NOTHING_IS_DECIDED] = sText_RefIfNothingIsDecided,
    [B_MSG_REF_THATS_IT]           = sText_RefThatsIt,
    [B_MSG_REF_JUDGE_MIND]         = sText_RefJudgeMind,
    [B_MSG_REF_JUDGE_SKILL]        = sText_RefJudgeSkill,
    [B_MSG_REF_JUDGE_BODY]         = sText_RefJudgeBody,
    [B_MSG_REF_PLAYER_WON]         = sText_RefPlayerWon,
    [B_MSG_REF_OPPONENT_WON]       = sText_RefOpponentWon,
    [B_MSG_REF_DRAW]               = sText_RefDraw,
    [B_MSG_REF_COMMENCE_BATTLE]    = sText_RefCommenceBattle,
};

static const u8 sText_QuestionForfeitMatch[] = _("{JPN}しあいを きけんして\nやめますか?");
static const u8 sText_ForfeitedMatch[] = _("{JPN}{B_PLAYER_NAME}は しあいを きけんした!");
static const u8 sText_Trainer1WinText[] = _("{B_TRAINER1_WIN_TEXT}");
static const u8 sText_Trainer2WinText[] = _("{B_TRAINER2_WIN_TEXT}");
static const u8 sText_Trainer1Fled[] = _("{JPN}{PLAY_SE SE_FLEE}{B_TRAINER1_CLASS} {B_TRAINER1_NAME}は にげだした!");
static const u8 sText_PlayerLostAgainstTrainer1[] = _("{JPN}{B_TRAINER1_CLASS} {B_TRAINER1_NAME}に\nまけた!");
static const u8 sText_PlayerBattledToDrawTrainer1[] = _("{JPN}{B_TRAINER1_CLASS} {B_TRAINER1_NAME}と\nひきわけた!");
const u8 gText_RecordBattleToPass[] = _("{JPN}バトルの きろくを\nフロンティアパスに のこしますか?");
const u8 gText_BattleRecordedOnPass[] = _("{JPN}{B_PLAYER_NAME}の バトルの けっかが\nフロンティアパスに きろくされた。");
static const u8 sText_LinkTrainerWantsToBattlePause[] = _("{JPN}{B_LINK_OPPONENT1_NAME}が\nしょうぶを しかけてきた!{PAUSE 49}");
static const u8 sText_TwoLinkTrainersWantToBattlePause[] = _("{JPN}{B_LINK_OPPONENT1_NAME}と {B_LINK_OPPONENT2_NAME}が\nしょうぶを しかけてきた!{PAUSE 49}");

// This is four lists of moves which use a different attack string in Japanese
// to the default. See the documentation for ChooseTypeOfMoveUsedString for more detail.
static const u16 sGrammarMoveUsedTable[] =
{
    MOVE_SWORDS_DANCE, MOVE_STRENGTH, MOVE_GROWTH,
    MOVE_HARDEN, MOVE_MINIMIZE, MOVE_SMOKESCREEN,
    MOVE_WITHDRAW, MOVE_DEFENSE_CURL, MOVE_EGG_BOMB,
    MOVE_SMOG, MOVE_BONE_CLUB, MOVE_FLASH, MOVE_SPLASH,
    MOVE_ACID_ARMOR, MOVE_BONEMERANG, MOVE_REST, MOVE_SHARPEN,
    MOVE_SUBSTITUTE, MOVE_MIND_READER, MOVE_SNORE,
    MOVE_PROTECT, MOVE_SPIKES, MOVE_ENDURE, MOVE_ROLLOUT,
    MOVE_SWAGGER, MOVE_SLEEP_TALK, MOVE_HIDDEN_POWER,
    MOVE_PSYCH_UP, MOVE_EXTREME_SPEED, MOVE_FOLLOW_ME,
    MOVE_TRICK, MOVE_ASSIST, MOVE_INGRAIN, MOVE_KNOCK_OFF,
    MOVE_CAMOUFLAGE, MOVE_ASTONISH, MOVE_ODOR_SLEUTH,
    MOVE_GRASS_WHISTLE, MOVE_SHEER_COLD, MOVE_MUDDY_WATER,
    MOVE_IRON_DEFENSE, MOVE_BOUNCE, 0,

    MOVE_TELEPORT, MOVE_RECOVER, MOVE_BIDE, MOVE_AMNESIA,
    MOVE_FLAIL, MOVE_TAUNT, MOVE_BULK_UP, 0,

    MOVE_MEDITATE, MOVE_AGILITY, MOVE_MIMIC, MOVE_DOUBLE_TEAM,
    MOVE_BARRAGE, MOVE_TRANSFORM, MOVE_STRUGGLE, MOVE_SCARY_FACE,
    MOVE_CHARGE, MOVE_WISH, MOVE_BRICK_BREAK, MOVE_YAWN,
    MOVE_FEATHER_DANCE, MOVE_TEETER_DANCE, MOVE_MUD_SPORT,
    MOVE_FAKE_TEARS, MOVE_WATER_SPORT, MOVE_CALM_MIND, 0,

    MOVE_POUND, MOVE_SCRATCH, MOVE_VICE_GRIP,
    MOVE_WING_ATTACK, MOVE_FLY, MOVE_BIND, MOVE_SLAM,
    MOVE_HORN_ATTACK, MOVE_WRAP, MOVE_THRASH, MOVE_TAIL_WHIP,
    MOVE_LEER, MOVE_BITE, MOVE_GROWL, MOVE_ROAR,
    MOVE_SING, MOVE_PECK, MOVE_ABSORB, MOVE_STRING_SHOT,
    MOVE_EARTHQUAKE, MOVE_FISSURE, MOVE_DIG, MOVE_TOXIC,
    MOVE_SCREECH, MOVE_METRONOME, MOVE_LICK, MOVE_CLAMP,
    MOVE_CONSTRICT, MOVE_POISON_GAS, MOVE_BUBBLE,
    MOVE_SLASH, MOVE_SPIDER_WEB, MOVE_NIGHTMARE, MOVE_CURSE,
    MOVE_FORESIGHT, MOVE_CHARM, MOVE_ATTRACT, MOVE_ROCK_SMASH,
    MOVE_UPROAR, MOVE_SPIT_UP, MOVE_SWALLOW, MOVE_TORMENT,
    MOVE_FLATTER, MOVE_ROLE_PLAY, MOVE_ENDEAVOR, MOVE_TICKLE,
    MOVE_COVET, 0
};

static const u8 sText_EmptyStatus[] = _("$$$$$$$");

static const struct BattleWindowText sTextOnWindowsInfo_Normal[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_PSS_ICON] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 2,
    },
    [B_WIN_VS_PLAYER] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_OPPONENT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fillValue = PIXEL_FILL(0x0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [24] = { // 24 "type" super-effective
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 6,
        .bgColor = 14,
        .shadowColor = 5,
    },
    [25] = { // 25 "type" not very effective
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 14,
        .shadowColor = 3,
    },
    [26] = { // 26 "type" no effect
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 7,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
};

static const struct BattleWindowText sTextOnWindowsInfo_Arena[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_PSS_ICON] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 2,
    },
    [ARENA_WIN_PLAYER_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_VS] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_OPPONENT_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_MIND] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_SKILL] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_BODY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_JUDGMENT_TITLE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_JUDGMENT_TEXT] = {
        .fillValue = PIXEL_FILL(0x1),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 2,
        .bgColor = 1,
        .shadowColor = 3,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fillValue = PIXEL_FILL(0x0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [24] = { // 24 "type" super-effective
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 6,
        .bgColor = 14,
        .shadowColor = 5,
    },
    [25] = { // 25 "type" not very effective
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 14,
        .shadowColor = 3,
    },
    [26] = { // 26 "type" no effect
        .fillValue = PIXEL_FILL(0xE),
        .fontId = 7,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = 7,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
};

static const struct BattleWindowText *const sBattleTextOnWindowsInfo[] =
{
    [B_WIN_TYPE_NORMAL] = sTextOnWindowsInfo_Normal,
    [B_WIN_TYPE_ARENA]  = sTextOnWindowsInfo_Arena
};

static const u8 sRecordedBattleTextSpeeds[] = {8, 4, 1, 0};

void BufferStringBattle(u16 stringID)
{
    s32 i;
    const u8 *stringPtr = NULL;

    gBattleMsgDataPtr = (struct BattleMsgData *)(&gBattleBufferA[gActiveBattler][4]);
    gLastUsedItem = gBattleMsgDataPtr->lastItem;
    gLastUsedAbility = gBattleMsgDataPtr->lastAbility;
    gBattleScripting.battler = gBattleMsgDataPtr->scrActive;
    *(&gBattleStruct->scriptPartyIdx) = gBattleMsgDataPtr->bakScriptPartyIdx;
    *(&gBattleStruct->hpScale) = gBattleMsgDataPtr->hpScale;
    gPotentialItemEffectBattler = gBattleMsgDataPtr->itemEffectBattler;
    *(&gBattleStruct->stringMoveType) = gBattleMsgDataPtr->moveType;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        sBattlerAbilities[i] = gBattleMsgDataPtr->abilities[i];
    }
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        gBattleTextBuff1[i] = gBattleMsgDataPtr->textBuffs[0][i];
        gBattleTextBuff2[i] = gBattleMsgDataPtr->textBuffs[1][i];
        gBattleTextBuff3[i] = gBattleMsgDataPtr->textBuffs[2][i];
    }

    switch (stringID)
    {
    case STRINGID_INTROMSG: // first battle msg
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    stringPtr = sText_TwoTrainersWantToBattle;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_TwoLinkTrainersWantToBattlePause;
                    else
                        stringPtr = sText_TwoLinkTrainersWantToBattle;
                }
                else
                {
                    if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1WantsToBattle;
                    else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_LinkTrainerWantsToBattlePause;
                    else
                        stringPtr = sText_LinkTrainerWantsToBattle;
                }
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                    stringPtr = sText_TwoTrainersWantToBattle;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersWantToBattle;
                else
                    stringPtr = sText_Trainer1WantsToBattle;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
                stringPtr = sText_LegendaryPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE) // interesting, looks like they had something planned for wild double battles
                stringPtr = sText_TwoWildPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
                stringPtr = sText_WildPkmnAppearedPause;
            else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
                stringPtr = sText_WildPkmnAppearedOld;
            else
                if (gSaveBlock2Ptr->optionsLRtoRun == 0)
                {
                    if (gSaveBlock2Ptr->optionsRunType == 1)
                        stringPtr = sText_WildPkmnAppeared;
                    else if (gSaveBlock2Ptr->optionsRunType == 3)
                        stringPtr = sText_WildPkmnAppeared_B;
                    else 
                        stringPtr = sText_WildPkmnAppearedOld;
                }
                else if (gSaveBlock2Ptr->optionsLRtoRun == 1)
                    stringPtr = sText_WildPkmnAppearedOld;
        }
        break;
    case STRINGID_INTROSENDOUT: // poke first send-out
        if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && IsValidForBattle(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler ^ BIT_FLANK]]))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                    stringPtr = sText_InGamePartnerSentOutZGoN;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_GoTwoPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_LinkPartnerSentOutPkmnGoPkmn;
                else
                    stringPtr = sText_GoTwoPkmn;
            }
            else
            {
                stringPtr = sText_GoPkmn;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_TwoLinkTrainersSentOutPkmn;
                else if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                    stringPtr = sText_LinkTrainerSentOutTwoPkmn;
                else
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
            }
            else
            {
                if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK)))
                    stringPtr = sText_Trainer1SentOutPkmn;
                else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                    stringPtr = sText_Trainer1SentOutPkmn;
                else
                    stringPtr = sText_LinkTrainerSentOutPkmn;
            }
        }
        break;
    case STRINGID_RETURNMON: // sending poke to ball msg
        if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        {
            if (*(&gBattleStruct->hpScale) == 0)
                stringPtr = sText_PkmnThatsEnough;
            else if (*(&gBattleStruct->hpScale) == 1 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                stringPtr = sText_PkmnComeBack;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_PkmnOkComeBack;
            else
                stringPtr = sText_PkmnGoodComeBack;
        }
        else
        {
            if (gTrainerBattleOpponent_A == TRAINER_LINK_OPPONENT || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_LinkTrainer2WithdrewPkmn;
                else
                    stringPtr = sText_LinkTrainer1WithdrewPkmn;
            }
            else
            {
                stringPtr = sText_Trainer1WithdrewPkmn;
            }
        }
        break;
    case STRINGID_SWITCHINMON: // switch-in msg
        if (GetBattlerSide(gBattleScripting.battler) == B_SIDE_PLAYER)
        {
            if (*(&gBattleStruct->hpScale) == 0 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                stringPtr = sText_GoPkmn2;
            else if (*(&gBattleStruct->hpScale) == 1)
                stringPtr = sText_DoItPkmn;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_GoForItPkmn;
            else
                stringPtr = sText_YourFoesWeakGetEmPkmn;
        }
        else
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                        stringPtr = sText_LinkTrainerMultiSentOutPkmn;
                    else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_LinkTrainerSentOutPkmn2;
                }
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    stringPtr = sText_Trainer1SentOutPkmn2;
                }
            }
        }
        break;
    case STRINGID_USEDMOVE: // Pokémon used a move msg
        ChooseMoveUsedParticle(gBattleTextBuff1); // buff1 doesn't appear in the string, leftover from japanese move names

        if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT)
            StringCopy(gBattleTextBuff2, sATypeMove_Table[*(&gBattleStruct->stringMoveType)]);
        else
            StringCopy(gBattleTextBuff2, gMoveNames[gBattleMsgDataPtr->currentMove]);

        ChooseTypeOfMoveUsedString(gBattleTextBuff2);
        stringPtr = sText_AttackerUsedX;
        break;
    case STRINGID_BATTLEEND: // battle end
        if (gBattleTextBuff1[0] & B_OUTCOME_LINK_BATTLE_RAN)
        {
            gBattleTextBuff1[0] &= ~(B_OUTCOME_LINK_BATTLE_RAN);
            if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTextBuff1[0] == B_OUTCOME_LOST || gBattleTextBuff1[0] == B_OUTCOME_DREW)
                stringPtr = sText_GotAwaySafely;
            else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                stringPtr = sText_TwoWildFled;
            else
                stringPtr = sText_WildFled;
        }
        else
        {
            if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                        stringPtr = sText_TwoInGameTrainersDefeated;
                    else
                        stringPtr = sText_TwoLinkTrainersDefeated;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostToTwo;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawVsTwo;
                    break;
                }
            }
            else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainerTrainer1;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstTrainer1;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawTrainer1;
                    break;
                }
            }
            else
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainer;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstLinkTrainer;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawLinkTrainer;
                    break;
                }
            }
        }
        break;
    case STRINGID_CANTESCAPE:
        stringPtr = sText_CantEscape;
        break;
    default: // load a string from the table
        if (stringID >= BATTLESTRINGS_COUNT)
        {
            gDisplayedStringBattle[0] = EOS;
            return;
        }
        else
        {
            stringPtr = gBattleStringsTable[stringID - BATTLESTRINGS_TABLE_START];
        }
        break;
    }

    BattleStringExpandPlaceholdersToDisplayedString(stringPtr);
}

u32 BattleStringExpandPlaceholdersToDisplayedString(const u8 *src)
{
    BattleStringExpandPlaceholders(src, gDisplayedStringBattle);
}

static const u8 *TryGetStatusString(u8 *src)
{
    u32 i;
    u8 status[8];
    u32 chars1, chars2;
    u8 *statusPtr;

    memcpy(status, sText_EmptyStatus, min(ARRAY_COUNT(status), ARRAY_COUNT(sText_EmptyStatus)));

    statusPtr = status;
    for (i = 0; i < ARRAY_COUNT(status); i++)
    {
        if (*src == EOS) break; // one line required to match -g
        *statusPtr = *src;
        src++;
        statusPtr++;
    }

    chars1 = *(u32 *)(&status[0]);
    chars2 = *(u32 *)(&status[4]);

    for (i = 0; i < ARRAY_COUNT(gStatusConditionStringsTable); i++)
    {
        if (chars1 == *(u32 *)(&gStatusConditionStringsTable[i][0][0])
            && chars2 == *(u32 *)(&gStatusConditionStringsTable[i][0][4]))
            return gStatusConditionStringsTable[i][1];
    }
    return NULL;
}

#define HANDLE_NICKNAME_STRING_CASE(battlerId, monIndex)                \
    if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)                     \
    {                                                                   \
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)                     \
            toCpy = sText_FoePkmnPrefix;                                \
        else                                                            \
            toCpy = sText_WildPkmnPrefix;                               \
        while (*toCpy != EOS)                                           \
        {                                                               \
            dst[dstID] = *toCpy;                                        \
            dstID++;                                                    \
            toCpy++;                                                    \
        }                                                               \
        GetMonData(&gEnemyParty[monIndex], MON_DATA_NICKNAME, text);    \
    }                                                                   \
    else                                                                \
    {                                                                   \
        GetMonData(&gPlayerParty[monIndex], MON_DATA_NICKNAME, text);   \
    }                                                                   \
    StringGet_Nickname(text);                                           \
    toCpy = text;

// Ensure the defined length for an item name can contain the full defined length of a berry name.
// This ensures that custom Enigma Berry names will fit in the text buffer at the top of BattleStringExpandPlaceholders.
STATIC_ASSERT(BERRY_NAME_LENGTH + ARRAY_COUNT(sText_BerrySuffix) <= ITEM_NAME_LENGTH, BerryNameTooLong);

u32 BattleStringExpandPlaceholders(const u8 *src, u8 *dst)
{
    u32 dstID = 0; // if they used dstID, why not use srcID as well?
    const u8 *toCpy = NULL;
    // This buffer may hold either the name of a trainer, Pokémon, or item.
    u8 text[max(max(max(32, TRAINER_NAME_LENGTH + 1), POKEMON_NAME_LENGTH + 1), ITEM_NAME_LENGTH)];
    u8 multiplayerId;
    s32 i;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        multiplayerId = gRecordedBattleMultiplayerId;
    else
        multiplayerId = GetMultiplayerId();

    while (*src != EOS)
    {
        if (*src == PLACEHOLDER_BEGIN)
        {
            src++;
            switch (*src)
            {
            case B_TXT_BUFF1:
                if (gBattleTextBuff1[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff1, gStringVar1);
                    toCpy = gStringVar1;
                }
                else
                {
                    toCpy = TryGetStatusString(gBattleTextBuff1);
                    if (toCpy == NULL)
                        toCpy = gBattleTextBuff1;
                }
                break;
            case B_TXT_BUFF2:
                if (gBattleTextBuff2[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff2, gStringVar2);
                    toCpy = gStringVar2;
                }
                else
                    toCpy = gBattleTextBuff2;
                break;
            case B_TXT_BUFF3:
                if (gBattleTextBuff3[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff3, gStringVar3);
                    toCpy = gStringVar3;
                }
                else
                    toCpy = gBattleTextBuff3;
                break;
            case B_TXT_COPY_VAR_1:
                toCpy = gStringVar1;
                break;
            case B_TXT_COPY_VAR_2:
                toCpy = gStringVar2;
                break;
            case B_TXT_COPY_VAR_3:
                toCpy = gStringVar3;
                break;
            case B_TXT_PLAYER_MON1_NAME: // first player poke name
                GetMonData(&gPlayerParty[gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON1_NAME: // first enemy poke name
                GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_PLAYER_MON2_NAME: // second player poke name
                GetMonData(&gPlayerParty[gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT)]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON2_NAME: // second enemy poke name
                GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT)]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON1_NAME: // link first player poke name
                GetMonData(&gPlayerParty[gBattlerPartyIndexes[gLinkPlayers[multiplayerId].id]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON1_NAME: // link first opponent poke name
                GetMonData(&gEnemyParty[gBattlerPartyIndexes[gLinkPlayers[multiplayerId].id ^ 1]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON2_NAME: // link second player poke name
                GetMonData(&gPlayerParty[gBattlerPartyIndexes[gLinkPlayers[multiplayerId].id ^ 2]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON2_NAME: // link second opponent poke name
                GetMonData(&gEnemyParty[gBattlerPartyIndexes[gLinkPlayers[multiplayerId].id ^ 3]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX_MON1: // attacker name with prefix, only battlerId 0/1
                HANDLE_NICKNAME_STRING_CASE(gBattlerAttacker,
                                            gBattlerPartyIndexes[GetBattlerAtPosition(GET_BATTLER_SIDE(gBattlerAttacker))])
                break;
            case B_TXT_ATK_PARTNER_NAME: // attacker partner name
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    GetMonData(&gPlayerParty[gBattlerPartyIndexes[GetBattlerAtPosition(GET_BATTLER_SIDE(gBattlerAttacker)) + 2]], MON_DATA_NICKNAME, text);
                else
                    GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetBattlerAtPosition(GET_BATTLER_SIDE(gBattlerAttacker)) + 2]], MON_DATA_NICKNAME, text);

                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX: // attacker name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerAttacker, gBattlerPartyIndexes[gBattlerAttacker])
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX: // target name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerTarget, gBattlerPartyIndexes[gBattlerTarget])
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX: // effect battlerId name with prefix
                HANDLE_NICKNAME_STRING_CASE(gEffectBattler, gBattlerPartyIndexes[gEffectBattler])
                break;
            case B_TXT_ACTIVE_NAME_WITH_PREFIX: // active battlerId name with prefix
                HANDLE_NICKNAME_STRING_CASE(gActiveBattler, gBattlerPartyIndexes[gActiveBattler])
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX: // scripting active battlerId name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattleScripting.battler, gBattlerPartyIndexes[gBattleScripting.battler])
                break;
            case B_TXT_CURRENT_MOVE: // current move name
                if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT)
                    toCpy = sATypeMove_Table[gBattleStruct->stringMoveType];
                else
                    toCpy = gMoveNames[gBattleMsgDataPtr->currentMove];
                break;
            case B_TXT_LAST_MOVE: // originally used move name
                if (gBattleMsgDataPtr->originallyUsedMove >= MOVES_COUNT)
                    toCpy = sATypeMove_Table[gBattleStruct->stringMoveType];
                else
                    toCpy = gMoveNames[gBattleMsgDataPtr->originallyUsedMove];
                break;
            case B_TXT_LAST_ITEM: // last used item
                if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                {
                    if (gLastUsedItem == ITEM_ENIGMA_BERRY)
                    {
                        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
                        {
                            if ((gBattleScripting.multiplayerId != 0 && (gPotentialItemEffectBattler & BIT_SIDE))
                                || (gBattleScripting.multiplayerId == 0 && !(gPotentialItemEffectBattler & BIT_SIDE)))
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                            {
                                toCpy = sText_EnigmaBerry;
                            }
                        }
                        else
                        {
                            if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                                toCpy = sText_EnigmaBerry;
                        }
                    }
                    else
                    {
                        CopyItemName(gLastUsedItem, text);
                        toCpy = text;
                    }
                }
                else
                {
                    CopyItemName(gLastUsedItem, text);
                    toCpy = text;
                }
                break;
            case B_TXT_LAST_ABILITY: // last used ability
                toCpy = gAbilityNames[gLastUsedAbility];
                break;
            case B_TXT_ATK_ABILITY: // attacker ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattlerAttacker]];
                break;
            case B_TXT_DEF_ABILITY: // target ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattlerTarget]];
                break;
            case B_TXT_SCR_ACTIVE_ABILITY: // scripting active ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattleScripting.battler]];
                break;
            case B_TXT_EFF_ABILITY: // effect battlerId ability
                toCpy = gAbilityNames[sBattlerAbilities[gEffectBattler]];
                break;
            case B_TXT_TRAINER1_CLASS: // trainer class name
                if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
                    toCpy = gTrainerClassNames[GetSecretBaseTrainerClass()];
                else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                    toCpy = gTrainerClassNames[GetUnionRoomTrainerClass()];
                else if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
                    toCpy = gTrainerClassNames[GetFrontierBrainTrainerClass()];
                else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                    toCpy = gTrainerClassNames[GetFrontierOpponentClass(gTrainerBattleOpponent_A)];
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                    toCpy = gTrainerClassNames[GetTrainerHillOpponentClass(gTrainerBattleOpponent_A)];
                else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
                    toCpy = gTrainerClassNames[GetEreaderTrainerClassId()];
                else
                    toCpy = gTrainerClassNames[gTrainers[gTrainerBattleOpponent_A].trainerClass];
                break;
            case B_TXT_TRAINER1_NAME: // trainer1 name
                if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
                {
                    for (i = 0; i < (s32) ARRAY_COUNT(gBattleResources->secretBase->trainerName); i++)
                        text[i] = gBattleResources->secretBase->trainerName[i];
                    text[i] = EOS;
                    ConvertInternationalString(text, gBattleResources->secretBase->language);
                    toCpy = text;
                }
                else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                {
                    toCpy = gLinkPlayers[multiplayerId ^ BIT_SIDE].name;
                }
                else if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
                {
                    CopyFrontierBrainTrainerName(text);
                    toCpy = text;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    GetFrontierTrainerName(text, gTrainerBattleOpponent_A);
                    toCpy = text;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    GetTrainerHillTrainerName(text, gTrainerBattleOpponent_A);
                    toCpy = text;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
                {
                    GetEreaderTrainerName(text);
                    toCpy = text;
                }
                else
                {
                    toCpy = gTrainers[gTrainerBattleOpponent_A].trainerName;
                    if (toCpy[0] == B_BUFF_PLACEHOLDER_BEGIN && toCpy[1] == B_TXT_RIVAL_NAME){
                        toCpy = GetExpandedPlaceholder(PLACEHOLDER_ID_RIVAL);
                    }
                }
                break;
            case B_TXT_LINK_PLAYER_NAME: // link player name
                toCpy = gLinkPlayers[multiplayerId].name;
                break;
            case B_TXT_LINK_PARTNER_NAME: // link partner name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT1_NAME: // link opponent 1 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT2_NAME: // link opponent 2 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id)))].name;
                break;
            case B_TXT_LINK_SCR_TRAINER_NAME: // link scripting active name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(gBattleScripting.battler)].name;
                break;
            case B_TXT_PLAYER_NAME: // player name
                if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                    toCpy = gLinkPlayers[0].name;
                else
                    toCpy = gSaveBlock2Ptr->playerName;
                break;
            case B_TXT_TRAINER1_LOSE_TEXT: // trainerA lose text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerALoseText();
                }
                break;
            case B_TXT_TRAINER1_WIN_TEXT: // trainerA win text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_26: // ?
                HANDLE_NICKNAME_STRING_CASE(gBattleScripting.battler, *(&gBattleStruct->scriptPartyIdx))
                break;
            case B_TXT_PC_CREATOR_NAME: // Bill pc
                if (FlagGet(FLAG_SYS_PC_BILL))
                    toCpy = sText_Bills;
                else
                    toCpy = sText_Someones;
                break;
            case B_TXT_ATK_PREFIX2:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_DEF_PREFIX2:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_ATK_PREFIX1:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_DEF_PREFIX1:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_ATK_PREFIX3:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_DEF_PREFIX3:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_TRAINER2_CLASS:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                    toCpy = gTrainerClassNames[GetFrontierOpponentClass(gTrainerBattleOpponent_B)];
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                    toCpy = gTrainerClassNames[GetTrainerHillOpponentClass(gTrainerBattleOpponent_B)];
                else
                    toCpy = gTrainerClassNames[gTrainers[gTrainerBattleOpponent_B].trainerClass];
                break;
            case B_TXT_TRAINER2_NAME:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    GetFrontierTrainerName(text, gTrainerBattleOpponent_B);
                    toCpy = text;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    GetTrainerHillTrainerName(text, gTrainerBattleOpponent_B);
                    toCpy = text;
                }
                else
                {
                    toCpy = gTrainers[gTrainerBattleOpponent_B].trainerName;
                }
                break;
            case B_TXT_TRAINER2_LOSE_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerBLoseText();
                }
                break;
            case B_TXT_TRAINER2_WIN_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_PARTNER_CLASS:
                toCpy = gTrainerClassNames[GetFrontierOpponentClass(gPartnerTrainerId)];
                break;
            case B_TXT_PARTNER_NAME:
                GetFrontierTrainerName(text, gPartnerTrainerId);
                toCpy = text;
                break;
            case B_TXT_RIVAL_NAME:
                toCpy = gSaveBlock2Ptr->rivalName;
                break;
            }

            // Strip redundant {JPN} prefix from substituted strings
            // (species/move names already contain {JPN}, but the template also has one)
            if (toCpy[0] == EXT_CTRL_CODE_BEGIN && toCpy[1] == EXT_CTRL_CODE_JPN)
                toCpy += 2;

            while (*toCpy != EOS)
            {
                dst[dstID] = *toCpy;
                dstID++;
                toCpy++;
            }
            if (*src == B_TXT_TRAINER1_LOSE_TEXT || *src == B_TXT_TRAINER2_LOSE_TEXT
                || *src == B_TXT_TRAINER1_WIN_TEXT || *src == B_TXT_TRAINER2_WIN_TEXT)
            {
                dst[dstID] = EXT_CTRL_CODE_BEGIN;
                dstID++;
                dst[dstID] = EXT_CTRL_CODE_PAUSE_UNTIL_PRESS;
                dstID++;
            }
        }
        else
        {
            dst[dstID] = *src;
            dstID++;
        }
        src++;
    }

    dst[dstID] = *src;
    dstID++;

    return dstID;
}

static void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst)
{
    u32 srcID = 1;
    u32 value = 0;
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u16 hword;

    *dst = EOS;
    while (src[srcID] != B_BUFF_EOS)
    {
        switch (src[srcID])
        {
        case B_BUFF_STRING: // battle string
            hword = T1_READ_16(&src[srcID + 1]);
            StringAppend(dst, gBattleStringsTable[hword - BATTLESTRINGS_TABLE_START]);
            srcID += 3;
            break;
        case B_BUFF_NUMBER: // int to string
            switch (src[srcID + 1])
            {
            case 1:
                value = src[srcID + 3];
                break;
            case 2:
                value = T1_READ_16(&src[srcID + 3]);
                break;
            case 4:
                value = T1_READ_32(&src[srcID + 3]);
                break;
            }
            ConvertIntToDecimalStringN(dst, value, STR_CONV_MODE_LEFT_ALIGN, src[srcID + 2]);
            srcID += src[srcID + 1] + 3;
            break;
        case B_BUFF_MOVE: // move name
            StringAppend(dst, gMoveNames[T1_READ_16(&src[srcID + 1])]);
            srcID += 3;
            break;
        case B_BUFF_TYPE: // type name
            StringAppend(dst, gTypeNames[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_MON_NICK_WITH_PREFIX: // poke nick with prefix
            if (GetBattlerSide(src[srcID + 1]) == B_SIDE_PLAYER)
            {
                GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                    StringAppend(dst, sText_FoePkmnPrefix);
                else
                    StringAppend(dst, sText_WildPkmnPrefix);

                GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            }
            StringGet_Nickname(nickname);
            StringAppend(dst, nickname);
            srcID += 3;
            break;
        case B_BUFF_STAT: // stats
            StringAppend(dst, gStatNamesTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_SPECIES: // species name
            GetSpeciesName(dst, T1_READ_16(&src[srcID + 1]));
            srcID += 3;
            break;
        case B_BUFF_MON_NICK: // poke nick without prefix
            if (GetBattlerSide(src[srcID + 1]) == B_SIDE_PLAYER)
                GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
            else
                GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
            StringGet_Nickname(dst);
            srcID += 3;
            break;
        case B_BUFF_NEGATIVE_FLAVOR: // flavor table
            StringAppend(dst, gPokeblockWasTooXStringTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_ABILITY: // ability names
            StringAppend(dst, gAbilityNames[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_ITEM: // item name
            hword = T1_READ_16(&src[srcID + 1]);
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (hword == ITEM_ENIGMA_BERRY)
                {
                    if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                    {
                        StringCopy(dst, gEnigmaBerries[gPotentialItemEffectBattler].name);
                        StringAppend(dst, sText_BerrySuffix);
                    }
                    else
                    {
                        StringAppend(dst, sText_EnigmaBerry);
                    }
                }
                else
                {
                    CopyItemName(hword, dst);
                }
            }
            else
            {
                CopyItemName(hword, dst);
            }
            srcID += 3;
            break;
        }
    }
}

// Loads one of two text strings into the provided buffer. This is functionally
// unused, since the value loaded into the buffer is not read; it loaded one of
// two particles (either "は" or "の") which works in tandem with ChooseTypeOfMoveUsedString
// below to effect changes in the meaning of the line.
static void ChooseMoveUsedParticle(u8 *textBuff)
{
    s32 counter = 0;
    u32 i = 0;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == 0)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    if (counter >= 0)
    {
        if (counter <= 2)
            StringCopy(textBuff, sText_SpaceIs); // is
        else if (counter <= MAX_MON_MOVES)
            StringCopy(textBuff, sText_ApostropheS); // 's
    }
}

// Appends "!" to the text buffer `dst`. In the original Japanese this looked
// into the table of moves at sGrammarMoveUsedTable and varied the line accordingly.
//
// sText_ExclamationMark was a plain "!", used for any attack not on the list.
// It resulted in the translation "<NAME>'s <ATTACK>!".
//
// sText_ExclamationMark2 was "を つかった!". This resulted in the translation
// "<NAME> used <ATTACK>!", which was used for all attacks in English.
//
// sText_ExclamationMark3 was "した!". This was used for those moves whose
// names were verbs, such as Recover, and resulted in translations like "<NAME>
// recovered itself!".
//
// sText_ExclamationMark4 was "を した!" This resulted in a translation of
// "<NAME> did an <ATTACK>!".
//
// sText_ExclamationMark5 was " こうげき!" This resulted in a translation of
// "<NAME>'s <ATTACK> attack!".
static void ChooseTypeOfMoveUsedString(u8 *dst)
{
    s32 counter = 0;
    s32 i = 0;

    while (*dst != EOS)
        dst++;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == MOVE_NONE)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    switch (counter)
    {
    case 0:
        StringCopy(dst, sText_ExclamationMark);
        break;
    case 1:
        StringCopy(dst, sText_ExclamationMark2);
        break;
    case 2:
        StringCopy(dst, sText_ExclamationMark3);
        break;
    case 3:
        StringCopy(dst, sText_ExclamationMark4);
        break;
    case 4:
        StringCopy(dst, sText_ExclamationMark5);
        break;
    }
}

void BattlePutTextOnWindow(const u8 *text, u8 windowId)
{
    const struct BattleWindowText *textInfo = sBattleTextOnWindowsInfo[gBattleScripting.windowsType];
    bool32 copyToVram;
    struct TextPrinterTemplate printerTemplate;
    u8 speed;

    if (windowId & B_WIN_COPYTOVRAM)
    {
        windowId &= ~B_WIN_COPYTOVRAM;
        copyToVram = FALSE;
    }
    else
    {
        FillWindowPixelBuffer(windowId, textInfo[windowId].fillValue);
        copyToVram = TRUE;
    }

    printerTemplate.currentChar = text;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = textInfo[windowId].fontId;
    printerTemplate.x = textInfo[windowId].x;
    printerTemplate.y = textInfo[windowId].y;
    printerTemplate.currentX = printerTemplate.x;
    printerTemplate.currentY = printerTemplate.y;
    printerTemplate.letterSpacing = textInfo[windowId].letterSpacing;
    printerTemplate.lineSpacing = textInfo[windowId].lineSpacing;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = textInfo[windowId].fgColor;
    printerTemplate.bgColor = textInfo[windowId].bgColor;
    printerTemplate.shadowColor = textInfo[windowId].shadowColor;

    if (printerTemplate.x == 0xFF)
    {
        u32 width = GetBattleWindowTemplatePixelWidth(gBattleScripting.windowsType, windowId);
        s32 alignX = GetStringCenterAlignXOffsetWithLetterSpacing(printerTemplate.fontId, printerTemplate.currentChar, width, printerTemplate.letterSpacing);
        printerTemplate.x = printerTemplate.currentX = alignX;
    }

    if (windowId == ARENA_WIN_JUDGMENT_TEXT)
        gTextFlags.useAlternateDownArrow = FALSE;
    else
        gTextFlags.useAlternateDownArrow = TRUE;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED))
        gTextFlags.autoScroll = TRUE;
    else
        gTextFlags.autoScroll = FALSE;

    if (windowId == B_WIN_MSG || windowId == ARENA_WIN_JUDGMENT_TEXT)
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            speed = 1;
        else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            speed = sRecordedBattleTextSpeeds[GetTextSpeedInRecordedBattle()];
        else
            speed = GetPlayerTextSpeedDelay();

        gTextFlags.canABSpeedUpPrint = 1;
    }
    else
    {
        speed = textInfo[windowId].speed;
        gTextFlags.canABSpeedUpPrint = 0;
    }

    AddTextPrinter(&printerTemplate, speed, NULL);

    if (copyToVram)
    {
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }
}

void SetPpNumbersPaletteInMoveSelection(void)
{
    struct ChooseMoveStruct *chooseMoveStruct = (struct ChooseMoveStruct *)(&gBattleBufferA[gActiveBattler][4]);
    const u16 *palPtr = gPPTextPalette;
    u8 var = GetCurrentPpToMaxPpState(chooseMoveStruct->currentPp[gMoveSelectionCursor[gActiveBattler]],
                         chooseMoveStruct->maxPp[gMoveSelectionCursor[gActiveBattler]]);

    gPlttBufferUnfaded[BG_PLTT_ID(5) + 12] = palPtr[(var * 2) + 0];
    gPlttBufferUnfaded[BG_PLTT_ID(5) + 11] = palPtr[(var * 2) + 1];

    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 12], &gPlttBufferFaded[BG_PLTT_ID(5) + 12], PLTT_SIZEOF(1));
    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 11], &gPlttBufferFaded[BG_PLTT_ID(5) + 11], PLTT_SIZEOF(1));
}

u8 GetCurrentPpToMaxPpState(u8 currentPp, u8 maxPp)
{
    if (maxPp == currentPp)
    {
        return 3;
    }
    else if (maxPp <= 2)
    {
        if (currentPp > 1)
            return 3;
        else
            return 2 - currentPp;
    }
    else if (maxPp <= 7)
    {
        if (currentPp > 2)
            return 3;
        else
            return 2 - currentPp;
    }
    else
    {
        if (currentPp == 0)
            return 2;
        if (currentPp <= maxPp / 4)
            return 1;
        if (currentPp > maxPp / 2)
            return 3;
    }

    return 0;
}
