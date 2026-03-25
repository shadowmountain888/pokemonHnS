.set LOCALID_WELL_KURT, 19

SlowpokeWell_B1F_MapScripts::
	.byte 0

SlowpokeWell_B1F_EventScript_Item_Super_Potion_1::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Super_Potion_2::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Great_Ball::
	finditem ITEM_GREAT_BALL
	end

SlowpokeWell_B1F_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

SlowpokeWell_B1F_EventScript_Kurt::
	lock
	msgbox SlowpokeWell_B1F_Text_KurtIntro, MSGBOX_DEFAULT
	closemessage
	end

SlowpokeWell_B1F_EventScript_Grunt21::
	trainerbattle_single TRAINER_GRUNT_21, SlowpokeWell_B1F_Text_GruntM29Seen, SlowpokeWell_B1F_Text_GruntM29Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM29After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Grunt22F::
	trainerbattle_single TRAINER_GRUNT_22, SlowpokeWell_B1F_Text_GruntF1Seen, SlowpokeWell_B1F_Text_GruntF1Beaten
	msgbox SlowpokeWell_B1F_Text_GruntF1After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Eto::
	trainerbattle_single TRAINER_ETO, SlowpokeWell_B1F_Text_GruntM2Seen, SlowpokeWell_B1F_Text_GruntM2Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM2After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Proton::
	lock
	faceplayer
	msgbox SlowpokeWell_B1F_Text_ProtonSeen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_PROTON_1, SlowpokeWell_B1F_Text_ProtonBeaten
	msgbox SlowpokeWell_B1F_Text_ProtonAfter, MSGBOX_AUTOCLOSE
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_AZALEA_TOWN_ROCKETS
	clearflag FLAG_HIDE_KURT_1
	addobject LOCALID_WELL_KURT
	removeobject 11
	removeobject 12
	removeobject 13
	delay 120
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_WELL_KURT, SlowpokeWell_B1F_Movement_Kurt
	waitmovement 0
	msgbox SlowpokeWell_B1F_Text_KurtAfter, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SLOWPOKE_WELL_KURT
	setflag FLAG_HIDE_KURT_1
	clearflag FLAG_HIDE_KURT_2
	clearflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setvar VAR_AZALEA_TOWN_STATE, 3
	warp MAP_AZALEA_TOWN_KURTS_HOUSE, 15, 4
	release
	end

SlowpokeWell_B1F_Movement_Kurt:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

SlowpokeWell_B1F_Text_KurtIntro:
	.string "{JPN}ガンテツ: やあ {PLAYER}!\p"
	.string "{JPN}うえの ばんにんは\n"
	.string "{JPN}おれが どなったら\l"
	.string "{JPN}にげていったよ.\p"
	.string "{JPN}だが そのあと いどに\n"
	.string "{JPN}おちてしまってな.\p"
	.string "{JPN}せなかを つよく\n"
	.string "{JPN}うちつけたから\l"
	.string "{JPN}うごけないんだ.\p"
	.string "{JPN}ちくしょう! げんきなら\n"
	.string "{JPN}おれの ポケモンが\l"
	.string "{JPN}やつらを こらしめて\lやったのに...\pああ しかたがない.\p{PLAYER} おれの かわりに\nきみの ゆうきを\lみせてやってくれ!$"

SlowpokeWell_B1F_Text_KurtAfter:
	.string "{JPN}ガンテツ: やったな {PLAYER}!\p"
	.string "{JPN}ロケットだんは にげていったぞ\p"
	.string "{JPN}わしの こしも よくなった\n"
	.string "{JPN}ここから でよう$"

SlowpokeWell_B1F_Text_GruntM29Seen:
	.string "{JPN}ちくしょう! うえで みはりを\n"
	.string "{JPN}してたら じじいに どなられて\l"
	.string "{JPN}びっくりした\p"
	.string "{JPN}こんな ところに\n"
	.string "{JPN}おちちまったじゃねーか\p"
	.string "{JPN}むしゃくしゃするから\n"
	.string "{JPN}きさまに あたってやる!$"

SlowpokeWell_B1F_Text_GruntM29Beaten:
	.string "{JPN}がああ! ついてねー ひだ!$"

SlowpokeWell_B1F_Text_GruntM29After:
	.string "{JPN}そうだ おれたちは ヤドンの\n"
	.string "{JPN}しっぽを きって うってるのさ\p"
	.string "{JPN}ぜんぶ きんもうけの ためだ\p"
	.string "{JPN}そうとも! おれたちは ロケット\n"
	.string "{JPN}だん! かねの ためなら\l"
	.string "{JPN}なんでも やるぜ!$"

SlowpokeWell_B1F_Text_ProtonSeen:
	.string "{JPN}なんの ようだ?\p"
	.string "{JPN}おれたちの じゃまを するなら\n"
	.string "{JPN}ようしゃは しないぞ!$"

SlowpokeWell_B1F_Text_ProtonBeaten:
	.string "{JPN}きょうは やるじゃないか\n"
	.string "{JPN}だが つぎは そうは いかない!$"

SlowpokeWell_B1F_Text_ProtonAfter:
	.string "{JPN}そうだ ロケットだんは さんねん\n"
	.string "{JPN}まえに かいさんした\p"
	.string "{JPN}ボスは すがたを くらました\p"
	.string "{JPN}だが おれたちは ちかで\n"
	.string "{JPN}かつどうを つづけていたのだ!\n"
	.string "{JPN}きさまみたいな ちいさな\n"
	.string "{JPN}じゃまものは たいした\l"
	.string "{JPN}もんだいじゃない\n"
	.string "{JPN}これから おこることを\nおそれて いるがいい!$"

SlowpokeWell_B1F_Text_GruntM2Seen:
	.string "{JPN}ひーひーひー!\n"
	.string "{JPN}ヤドンの しっぽうりを やめろ?\p"
	.string "{JPN}ばかじゃねーの!\n"
	.string "{JPN}きさまの いうことなんか きいて\n"
	.string "{JPN}たら ロケットだんの めんつが\lまるつぶれだ!$"

SlowpokeWell_B1F_Text_GruntM2Beaten:
	.string "{JPN}うへへ...\n"
	.string "{JPN}つよすぎる...$"
SlowpokeWell_B1F_Text_GruntM2After:
	.string "{JPN}かねは ひつようだけど\n"
	.string "{JPN}ヤドンの しっぽを うるなんて\p"
	.string "{JPN}ロケットだんの したっぱは\nつらいぜ!$"

SlowpokeWell_B1F_Text_GruntF1Seen:
	.string "{JPN}しっぽとりを やめろって?\p"
	.string "{JPN}あたしたち ぜんいんを\n"
	.string "{JPN}たおしてから いいなさい!$"

SlowpokeWell_B1F_Text_GruntF1Beaten:
	.string "{JPN}この くそがき!$"

SlowpokeWell_B1F_Text_GruntF1After:
	.string "{JPN}ヤドンの しっぽは すぐ\n"
	.string "{JPN}はえてくるのよ!\pうって なにが わるいの?$"

SlowpokeWell_B1F_Text_SlowpokeWithMail:
	.string "{JPN}しっぽを きられた\n"
	.string "{JPN}ヤドンが いる...\p"
	.string "{JPN}あれ? てがみを もってる.\nよんでみる?$"

SlowpokeWell_B1F_Text_SlowpokeMail:
	.string "{JPN}{PLAYER}は てがみを よんだ\p"
	.string "{JPN}いいこに して おじいちゃんと\n"
	.string "{JPN}ヤドンと おるすばんしててね\p"
	.string "{JPN}とうさんより$"

SlowpokeWell_B1F_Text_TaillessSlowpoke:
	.string "{JPN}しっぽを きられた\nヤドンが いる...$"
