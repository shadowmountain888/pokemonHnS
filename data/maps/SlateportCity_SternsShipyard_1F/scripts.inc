.set LOCALID_DOCK, 1

SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_GARBAGEFLAG
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "{JPN}うーん... これを ここに おいて\n"
	.string "{JPN}それを あっちに おくと...\p"
	.string "{JPN}じゃあ この ぶひんは どこに\n"
	.string "{JPN}いくんだろう?\n"
	.string "{JPN}あの どうぐは?\p"
	.string "{JPN}あーあ! ぜんぜん\nわからないよ!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "{JPN}ん?\n"
	.string "{JPN}やあ ぼくは ドックだ\p"
	.string "{JPN}キャプテン クスノキに たのまれて\n"
	.string "{JPN}フェリーを せっけい してるんだ\p"
	.string "{JPN}お! それは...\n"
	.string "{JPN}デボンの しなもの?\p"
	.string "{JPN}でも うーん...\n"
	.string "{JPN}こまったな...\p"
	.string "{JPN}キャプテン クスノキは でかけて\n"
	.string "{JPN}しまったんだ\n"
	.string "{JPN}しごとが あるって いってたよ\p"
	.string "{JPN}キャプテン クスノキを みつけて\nそれを とどけて くれないか?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "{JPN}ドック:クスノキせんちょうは\n"
	.string "{JPN}どこにいってしまったのかな?\p"
	.string "{JPN}クスノキせんちょうをさがして\n"
	.string "{JPN}このにもつをとどけてくれるかい?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "{JPN}ドック: ふねづくりは げいじゅつだ\p"
	.string "{JPN}おおくの ことは けいさんだけじゃ\n"
	.string "{JPN}わからないんだよ\p"
	.string "{JPN}うみを しっている ベテランの\n"
	.string "{JPN}アドバイスが ほしいなあ...$"
SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "{JPN}ドック:やあ! ハギろうじんさんが\n"
	.string "{JPN}てつだいにきてくれたよ.\p"
	.string "{JPN}ベテランのふなのりさんのおかげで\n"
	.string "{JPN}フェリーがちゃくちゃくとできてるよ$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "{JPN}ドック:フェリーがついにかんせい\n"
	.string "{JPN}したよ!\p"
	.string "{JPN}あたらしいS.S.タイダルは\n"
	.string "{JPN}ほんとうにぎじゅつのけっしょうだ!\p"
	.string "{JPN}でも もっといいものが\n"
	.string "{JPN}つくれるきがするんだ.\p"
	.string "{JPN}ぎじゅつのしんぽにおわりは\nないからね.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "{JPN}ハギろうじん:おお {PLAYER}{KUN}!\n"
	.string "{JPN}ひさしぶりじゃな!\p"
	.string "{JPN}うむ おまえにあってから\n"
	.string "{JPN}このふるいうみいぬがげんきになった!\p"
	.string "{JPN}それでドックのフェリーづくりを\n"
	.string "{JPN}てつだうことにしたのじゃ.\p"
	.string "{JPN}うむ フェリーならたくさんの\n"
	.string "{JPN}ひとをはこべるからのう.\p"
	.string "{JPN}しかしあのドックはほんとうに\n"
	.string "{JPN}すごいやつじゃ.\l"
	.string "{JPN}やつのぎじゅつとわしのけいけんで\n"
	.string "{JPN}すばらしいふねがつくれるはずじゃ!$"
	.string ""

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "{JPN}きせつや てんき つきの\n"
	.string "{JPN}いちなど...\p"
	.string "{JPN}そういう じょうけんで\n"
	.string "{JPN}うみは ひょうじょうを かえる\p"
	.string "{JPN}そうだ!\n"
	.string "{JPN}うみは いきものみたいだ!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "{JPN}ぼく ふなよいしやすいんだ.\n"
	.string "{JPN}だからここでおてつだいするよ.$"

