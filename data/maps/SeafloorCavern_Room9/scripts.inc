.set LOCALID_KYOGRE, 1
.set LOCALID_ARCHIE, 2
.set LOCALID_MAXIE, 3
.set LOCALID_GRUNT_1, 4
.set LOCALID_GRUNT_2, 5
.set LOCALID_KYOGRE_SLEEPING, 7

SeafloorCavern_Room9_MapScripts::
	.byte 0

SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre::
	lockall
	setvar VAR_0x8004, LOCALID_ARCHIE
	setvar VAR_0x8005, LOCALID_MAXIE
	setvar VAR_0x8006, LOCALID_GRUNT_1
	setvar VAR_0x8007, LOCALID_GRUNT_2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
	waitmovement 0
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8004
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CASSIE, SeafloorCavern_Room9_Text_ArchieDefeat
	msgbox SeafloorCavern_Room9_Text_ArchieWithThisRedOrb, MSGBOX_DEFAULT
	setweather WEATHER_NONE
	doweather
	special Script_FadeOutMapMusic
	waitstate
	msgbox SeafloorCavern_Room9_Text_RedOrbShinesByItself, MSGBOX_DEFAULT
	special WaitWeather
	waitstate
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 16, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	closemessage
	setvar VAR_RESULT, 0
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_KYOGRE_SLEEPING
	addobject LOCALID_KYOGRE
	waitstate
	delay 60
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
	waitmovement 0
	removeobject LOCALID_KYOGRE
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_0x8004, LOCALID_ARCHIE
	setvar VAR_0x8005, LOCALID_MAXIE
	setvar VAR_0x8006, LOCALID_GRUNT_1
	setvar VAR_0x8007, LOCALID_GRUNT_2
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
	playse SE_PC_LOGIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_OFF
	delay 20
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8005
	addobject VAR_0x8006
	addobject VAR_0x8007
	applymovement VAR_0x8007, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8006, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieArrive
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x8004, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_Delay48
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty, MSGBOX_DEFAULT
	msgbox SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieExit
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieExit
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieComeOnPlayer, MSGBOX_DEFAULT
	setvar VAR_GARBAGEVAR, 1
	setvar VAR_GARBAGEVAR, 1
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_GARBAGEFLAG
	setvar VAR_STEVENS_HOUSE_STATE, 2
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_ROUTE128, 38, 22
	waitstate
	releaseall
	end

SeafloorCavern_Room9_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_Unused1:
	walk_left
	walk_left
	step_end

SeafloorCavern_Room9_Movement_ArchieListenMessage:
	walk_left
	delay_16
	step_end

SeafloorCavern_Room9_Movement_Unused2:
	walk_right
	step_end

SeafloorCavern_Room9_Movement_ArchieExit:
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	walk_in_place_faster_right
	step_end

SeafloorCavern_Room9_Movement_KyogreApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Movement_KyogreExit:
	slide_up
	slide_up
	step_end

SeafloorCavern_Room9_Movement_MaxieArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_MaxieExit:
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_MagmaGruntArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_Delay32:
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Text_ArchieHoldItRightThere:
	.string "{JPN}アオギリ: そこで とまれ!$"

SeafloorCavern_Room9_Text_ArchieSoItWasYou:
	.string "{JPN}アオギリ: ふふふ...\n"
	.string "{JPN}やはり きみだったか$"

SeafloorCavern_Room9_Text_ArchieBeholdKyogre:
	.string "{JPN}アオギリ: みよ!\p"
	.string "{JPN}この うつくしき すがたを!\n"
	.string "{JPN}こだいポケモン カイオーガの\l"
	.string "{JPN}ねむる すがたを!\p"
	.string "{JPN}この ひが くることを\nどれほど まっていたことか...$"
SeafloorCavern_Room9_Text_ArchieYouMustDisappear:
	.string "{JPN}アオギリ: おどろいたぞ.\n"
	.string "{JPN}よくも ここまで おってきたな.\p"
	.string "{JPN}だが もう おわりだ.\p"
	.string "{JPN}おれの ゆめを かなえるため\n"
	.string "{JPN}おまえは きえてもらう!$"

SeafloorCavern_Room9_Text_ArchieDefeat:
	.string "{JPN}なんだと!?\n"
	.string "{JPN}こんな がきに まけるとは!!$"

SeafloorCavern_Room9_Text_ArchieWithThisRedOrb:
	.string "{JPN}アオギリ: ふふふ...\p"
	.string "{JPN}きみを みとめよう\n"
	.string "{JPN}たしかに さいのうが あるようだ\p"
	.string "{JPN}しかし!\n"
	.string "{JPN}わたしには これが あるのだ!\p"
	.string "{JPN}この あかいたまで\nカイオーガを...$"
SeafloorCavern_Room9_Text_RedOrbShinesByItself:
	.string "{JPN}べにいろのたまが とつぜん\n"
	.string "{JPN}ひとりでに ひかりはじめた!$"

SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo:
	.string "{JPN}アオギリ: なに?!\p"
	.string "{JPN}なにも していないのに...\n"
	.string "{JPN}なぜ あかいたまが...\p"
	.string "{JPN}カイオーガは どこへ いった?$"

SeafloorCavern_Room9_Text_ArchieAMessageFromOutside:
	.string "{JPN}アオギリ: ん? そとにいる\n"
	.string "{JPN}ぶかからの れんらくだ...$"
SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard:
	.string "{JPN}アオギリ: ああ なんだ?\p"
	.string "{JPN}ふむ...\n"
	.string "{JPN}はげしい あめが ふっている?\p"
	.string "{JPN}よい... それで ただしいのだ\n"
	.string "{JPN}カイオーガを めざめさせたのは\l"
	.string "{JPN}うみを ひろげるという\l"
	.string "{JPN}アクアだんの やぼうのため\p"
	.string "{JPN}なに?!\p"
	.string "{JPN}よそうを こえる はげしい あめで\n"
	.string "{JPN}きけんな じょうきょう だと?\p"
	.string "{JPN}そんな ばかな...\n"
	.string "{JPN}そんなことは ありえない...\p"
	.string "{JPN}その ばで たいきし\n"
	.string "{JPN}jょうきょうを かんしせよ!$"

SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear:
	.string "{JPN}アオギリ: なにかが おかしい...\p"
	.string "{JPN}あかいたまは カイオーガを\n"
	.string "{JPN}めざめさせ しはいするもののはず...\p"
	.string "{JPN}だが... なぜだ?\n"
	.string "{JPN}なぜ カイオーガは きえたのだ?\p"
	.string "{JPN}なぜだ?!$"

SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought:
	.string "{JPN}マツブサ: なんということを\n"
	.string "{JPN}しでかしたのだ?\p"
	.string "{JPN}アオギリ... ついに カイオーガを\n"
	.string "{JPN}めざめさせたな?\p"
	.string "{JPN}この おおあめが えいえんに\n"
	.string "{JPN}つづいたら せかいは どうなる?\n"
	.string "{JPN}りくちは ふかくなる うみに\nしずんでしまうではないか...$"
SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty:
	.string "{JPN}アオギリ: な-なに?!\n"
	.string "{JPN}えらそうに いうな!\p"
	.string "{JPN}グラードンを おこらせたのは\n"
	.string "{JPN}きさまら マグマだんでは ないか?\p"
	.string "{JPN}この あかいたまが あるかぎり\n"
	.string "{JPN}カイオーガを しはいできるはず...\p"
	.string "{JPN}しはいできるはずなのだ...$"
SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue:
	.string "{JPN}マツブサ: ここで いいあらそう\n"
	.string "{JPN}じかんなど ない!\p"
	.string "{JPN}そとに でて じぶんの めで\n"
	.string "{JPN}みろ!\p"
	.string "{JPN}おまえが やったことが\nのぞんだ せかいなのか みろ!$"

SeafloorCavern_Room9_Text_MaxieComeOnPlayer:
	.string "{JPN}マツブサ: {PLAYER}よ おまえも\n"
	.string "{JPN}はやく ここから でるんだ!$"
