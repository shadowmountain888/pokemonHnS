.set LOCALID_ROUTE10_SURGE, 8
.set LOCALID_ROUTE10_ZAPDOS, 2

Route10_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route10_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route10_EventScript_Surge::
    lock
    faceplayer
    msgbox Route10_Text_Surge, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_PLANT_SURGE
    removeobject LOCALID_ROUTE10_SURGE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_SURGE
    release
    end

Route10_Text_Surge:
    .string "{JPN}おーい ぼうず!\p"
	.string "{JPN}このへんは きをつけろよ \n"
	.string "{JPN}でんりょくが みちあふれてる!\p"
	.string "{JPN}さいせんしたけりゃ \n"
	.string "{JPN}かくとうどうじょうに きな!$"

Route10_EventScript_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route10_EventScript_Jim::
	trainerbattle_single TRAINER_JIM Route10_Text_HikerJimSeen, Route10_Text_HikerJimBeaten
	msgbox Route10_Text_HikerJimAfter, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Robert::
	trainerbattle_single TRAINER_ROBERT Route10_Text_PokefanmRobertSeen, Route10_Text_PokefanmRobertBeaten
	msgbox Route10_Text_PokefanmRobertAfter, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Sign::
	msgbox Route10_Text_Sign, MSGBOX_SIGN
	end

Route10_EventScript_PPSign::
	msgbox Route10_Text_PowerPlant, MSGBOX_SIGN
	end

Route10_EventScript_Zapdos::
	lock
	faceplayer
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
	msgbox SeafoamIslands_B1F_Text_ArticunoBattle
	delay 40
	waitmoncry
	seteventmon SPECIES_ZAPDOS, 50
	special BattleSetup_StartLegendaryBattle
waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route10_EventScript_ZapdosRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE10_ZAPDOS
	setflag FLAG_HIDE_ZAPDOS
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

Route10_EventScript_ZapdosRan::
	release
	end


Route10_Text_HikerJimSeen:
	.string "{JPN}はっはっはっは!$"

Route10_Text_HikerJimBeaten:
	.string "{JPN}はっはっは はっくしょん!$"

Route10_Text_HikerJimAfter:
	.string "{JPN}かふんしょうで くしゃみが\n"
	.string "{JPN}とまらないんだ!\nあはは はっくしょん!$"

Route10_Text_PokefanmRobertSeen:
	.string "{JPN}きみも ポケモンが\n"
	.string "{JPN}すきなんだろ?\pぼくも だいすきだよ!$"

Route10_Text_PokefanmRobertBeaten:
	.string "{JPN}これは ぼくの まけだね.$"

Route10_Text_PokefanmRobertAfter:
	.string "{JPN}Look what you did to my POKéMON...\p"
	.string "{JPN}I won't forget this...$"
Route10_Text_PowerPlant:
	.string "{JPN}はつでんしょ$"

Route10_Text_Sign:
	.string "{JPN}10ばんどうろ\p"
	.string "{JPN}ハナダシティ - シオンタウン$"
