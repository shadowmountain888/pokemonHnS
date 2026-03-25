.set LOCALID_WALLYS_DAD, 1

PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_GARBAGEVAR, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_GARBAGEVAR, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "{JPN}あなたは...\n"
	.string "{JPN}ああ {PLAYER}{KUN}ですね?\p"
	.string "{JPN}さきほどは ミツルと\n"
	.string "{JPN}あそんでくれて ありがとう.\p"
	.string "{JPN}あのこは あかちゃんのころから\n"
	.string "{JPN}からだが よわくて...\p"
	.string "{JPN}しんせきの いる\n"
	.string "{JPN}シダケタウンに あずけました.\p"
	.string "{JPN}こちらより くうきが\n"
	.string "{JPN}きれいですから.\p"
	.string "{JPN}え? ミツルは どこって?\n"
	.string "{JPN}もう でかけましたよ.\p"
	.string "{JPN}いまごろ どこまで\n"
	.string "{JPN}いったでしょうね?$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "{JPN}うちの ミツル げんき に\nしてるかしら?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{JPN}{PLAYER}くん!\n"
	.string "{JPN}こんな ふうに きゅうに\n"
	.string "{JPN}よんでしまって ごめんなさい.\p"
	.string "{JPN}でも うちの ミツルが\n"
	.string "{JPN}ハジツゲタウンに いってから\n"
	.string "{JPN}とても げんき になったの.\p"
	.string "{JPN}ぜんぶ あなたの おかげよ!\p"
	.string "{JPN}ミツルが まちを でるとき\n"
	.string "{JPN}ポケモンを つかまえるのを\n"
	.string "{JPN}てつだってくれたでしょう?\p"
	.string "{JPN}あれで ミツルは ほんとうに\n"
	.string "{JPN}うれしかったと おもうの.\p"
	.string "{JPN}じつは ミツルだけじゃなくて\n"
	.string "{JPN}ちちおやの わたしも\n"
	.string "{JPN}うれしかったのよ.\pあなたみたいな すてきな\nともだちが できて.\pこれは わいろじゃないけど\nぜひ もらってほしいの.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "{JPN}ポケモンが なみのりを\n"
	.string "{JPN}おぼえてると いろんな\nばしょに いけるのよ.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "{JPN}ミツルが もうすぐ\n"
	.string "{JPN}かえってくるの.\nたのしみだわ.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "{JPN}あら? サイユウシティで\n"
	.string "{JPN}ミツルに あったって?\p"
	.string "{JPN}あら {PLAYER}くん\n"
	.string "{JPN}そんな ばかな.\p"
	.string "{JPN}たしかに げんきに なったけど\n"
	.string "{JPN}そんな とおいところまで\lひとりで いけるわけないわ.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "{JPN}ミツルが ポケモンを\n"
	.string "{JPN}つかまえたって はなしたとき\n"
	.string "{JPN}ほんとうに うれしそうだった.\p"
	.string "{JPN}あんな えがおを みるのは\nひさしぶりだったわ.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "{JPN}しゅじんには ないしょに\n"
	.string "{JPN}してほしいのですが...\p"
	.string "{JPN}ミツルったら シダケタウンを\n"
	.string "{JPN}だまって でていって...\p"
	.string "{JPN}からだは よわいですが\n"
	.string "{JPN}いがいと いしが つよくて.\p"
	.string "{JPN}きっと げんきに\n"
	.string "{JPN}かえってきますよ!$"

