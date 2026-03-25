.set LOCALID_SSAQUA_B1F_SAILORLOOKING, 10

SSAqua_B1F_MapScripts::
	.byte 0

SSAqua_B1F_EventScript_Trigger::
	lock
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0 
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_SOUTH
	release
	end

SSAqua_B1F_EventScript_SailorLookingForBuddy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SSAQUA_SAILOR, SSAqua_B1F_EventScript_SailorLookingFoundBuddy
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SailorLookingFoundBuddy::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorThanks, MSGBOX_DEFAULT
	goto_if_lt VAR_SSAQUA_STATE, 5, SSAqua_B1F_EventScript_SailorGirl
	closemessage
	release
	end
SSAqua_B1F_EventScript_SailorGirl::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorSawGirl, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SleepySailor::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorDirections, MSGBOX_NPC
	end

SSAqua_B1F_EventScript_Barfcan::
	msgbox SSAqua_B1F_Text_BarfCan, MSGBOX_SIGN
	end

SSAqua_B1F_Text_BarfCan:
    .string "{JPN}うえっ!\n"
	.string "{JPN}みちゃだめだった!$"

SSAqua_B1F_Text_FastShipOnDutySailor:
	.string "{JPN}よお こども.\n"
	.string "{JPN}そうだんがあるんだ.\p"
	.string "{JPN}おれのなかまを\n"
	.string "{JPN}さがしてくれないか?\p"
	.string "{JPN}どこかで さぼってるんだ\n"
	.string "{JPN}あのなまけもの!\pおれがさがしたいんだが\nいまばんについてるんだ.$"

SSAqua_B1F_Text_FastShipOnDutySailorRefused:
	.string "{JPN}ああ こまった...\p"
	.string "{JPN}せんちょうが おこるだろうなあ...$"
SSAqua_B1F_Text_FastShipOnDutySailorThanks:
	.string "{JPN}ありがとよ こども!\n"
	.string "{JPN}がつんといってやったから\nもうさぼらないぜ!$"

SSAqua_B1F_Text_FastShipOnDutySailorSawGirl:
	.string "{JPN}ちいさなおんなのこ?\p"
	.string "{JPN}このへんを とおっていったかも\nしれないな.$"

SSAqua_B1F_Text_FastShipOnDutySailorDirections:
	.string "{JPN}この さきが だいにんぐだ.\p"
	.string "{JPN}おくの かいだんのうえが\n"
	.string "{JPN}せんちょうしつだぞ.$"

SSAqua_B1F_EventScript_Jeff::
	trainerbattle_single TRAINER_JEFF SSAqua_B1F_Text_SailorJeffSeen, SSAqua_B1F_Text_SailorJeffBeaten
	msgbox SSAqua_B1F_Text_SailorJeffAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorJeffSeen:
	.string "{JPN}やすみじかんの バトルは\n"
	.string "{JPN}さいこうだぜ!$"

SSAqua_B1F_Text_SailorJeffBeaten:
	.string "{JPN}かっても まけても\nやすみじかん おわりだ!$"

SSAqua_B1F_Text_SailorJeffAfter:
	.string "{JPN}ほんきに ならないと\n"
	.string "{JPN}かてないな.$"

SSAqua_B1F_EventScript_Debra::
	trainerbattle_single TRAINER_DEBRA SSAqua_B1F_Text_PicnickerDebraSeen, SSAqua_B1F_Text_PicnickerDebraBeaten
	msgbox SSAqua_B1F_Text_PicnickerDebraAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_PicnickerDebraSeen:
	.string "{JPN}たいくつよ.\nバトルしない?$"

SSAqua_B1F_Text_PicnickerDebraBeaten:
	.string "{JPN}きゃー!\nつよすぎるわよ!$"

SSAqua_B1F_Text_PicnickerDebraAfter:
	.string "{JPN}ヤマブキに タマムシ... カントーには\n"
	.string "{JPN}おおきな まちが たくさんあるって\nきいたよ$"

SSAqua_B1F_EventScript_Fritz::
	trainerbattle_single TRAINER_FRITZ SSAqua_B1F_Text_JugglerFritzSeen, SSAqua_B1F_Text_JugglerFritzBeaten
	msgbox SSAqua_B1F_Text_JugglerFritzAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_JugglerFritzSeen:
	.string "{JPN}うう... ふなよいしちゃった!$"
SSAqua_B1F_Text_JugglerFritzBeaten:
	.string "{JPN}もう うごけない...$"
SSAqua_B1F_Text_JugglerFritzAfter:
	.string "{JPN}もう ふねは こりごりだ.\n"
	.string "{JPN}こんどは\p"
	.string "{JPN}リニアでいこう.$"

SSAqua_B1F_EventScript_Garrett::
	trainerbattle_single TRAINER_GARRETT SSAqua_B1F_Text_SailorGarrettSeen, SSAqua_B1F_Text_SailorGarrettBeaten
	msgbox SSAqua_B1F_Text_SailorGarrettAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorGarrettSeen:
	.string "{JPN}ここは おれたち ふなのりの\nしごとばだ!$"

SSAqua_B1F_Text_SailorGarrettBeaten:
	.string "{JPN}ホームで まけちゃった...$"
SSAqua_B1F_Text_SailorGarrettAfter:
	.string "{JPN}クチバシティから\n"
	.string "{JPN}アサギシティまで\p"
	.string "{JPN}いろんなきゃくがのるんだ.$"

SSAqua_B1F_EventScript_Jonah::
	trainerbattle_single TRAINER_JONAH SSAqua_B1F_Text_FisherJonahSeen, SSAqua_B1F_Text_FisherJonahBeaten
	msgbox SSAqua_B1F_Text_FisherJonahAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_FisherJonahSeen:
	.string "{JPN}うみのうえなのに\n"
	.string "{JPN}つりができないなんて!\p"
	.string "{JPN}つまらん! バトルしよう!$"

SSAqua_B1F_Text_FisherJonahBeaten:
	.string "{JPN}もう... たいくつじゃなくなったよ...$"
SSAqua_B1F_Text_FisherJonahAfter:
	.string "{JPN}クチバの つりばしから\n"
	.string "{JPN}つりをする よていなんだ.$"

SSAqua_B1F_EventScript_Wai::
	trainerbattle_single TRAINER_WAI SSAqua_B1F_Text_BlackbeltWaiSeen, SSAqua_B1F_Text_BlackbeltWaiBeaten
	msgbox SSAqua_B1F_Text_BlackbeltWaiAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_BlackbeltWaiSeen:
	.string "{JPN}ふねの ゆれに たえて\n"
	.string "{JPN}あしを\p"
	.string "{JPN}きたえているのだ!$"

SSAqua_B1F_Text_BlackbeltWaiBeaten:
	.string "{JPN}ゆれて ころがった!$"

SSAqua_B1F_Text_BlackbeltWaiAfter:
	.string "{JPN}ジョウトでは\n"
	.string "{JPN}カラテおうがみつからなかった.\p"
	.string "{JPN}どこかの ほらあなで\n"
	.string "{JPN}しゅぎょうしているらしい.$"

SSAqua_B1F_EventScript_Kenneth::
	trainerbattle_single TRAINER_KENNETH SSAqua_B1F_Text_SailorKennethSeen, SSAqua_B1F_Text_SailorKennethBeaten
	msgbox SSAqua_B1F_Text_SailorKennethAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorKennethSeen:
	.string "{JPN}おれは ふなのりだ!\p"
	.string "{JPN}でも ポケモンを そだてて\n"
	.string "{JPN}チャンピオンになるぞ!$"

SSAqua_B1F_Text_SailorKennethBeaten:
	.string "{JPN}しゅぎょうぶそくが バレちゃった...$"
SSAqua_B1F_Text_SailorKennethAfter:
	.string "{JPN}8この バッジ!\n"
	.string "{JPN}ジムリーダーに かったしょうこ\n"
	.string "{JPN}なんだな.\p"
	.string "{JPN}なるほど つよいわけだ!$"

SSAqua_B1F_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY SSAqua_B1F_Text_TeacherShirleySeen, SSAqua_B1F_Text_TeacherShirleyBeaten
	msgbox SSAqua_B1F_Text_TeacherShirleyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_TeacherShirleySeen:
	.string "{JPN}わたしの せいとたちに\n"
	.string "{JPN}ゆびいっぽん ふれさせません!$"

SSAqua_B1F_Text_TeacherShirleyBeaten:
	.string "{JPN}きゃー!$"

SSAqua_B1F_Text_TeacherShirleyAfter:
	.string "{JPN}キキョウの そとにある\n"
	.string "{JPN}いせきに けんがくよ.$"

SSAqua_B1F_EventScript_Nate::
	trainerbattle_single TRAINER_NATE SSAqua_B1F_Text_SchoolboyNateSeen, SSAqua_B1F_Text_SchoolboyNateBeaten
	msgbox SSAqua_B1F_Text_SchoolboyNateAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyNateSeen:
	.string "{JPN}アルフのいせきを\nしってる?$"

SSAqua_B1F_Text_SchoolboyNateBeaten:
	.string "{JPN}うわー!$"

SSAqua_B1F_Text_SchoolboyNateAfter:
	.string "{JPN}アルフのいせきの なかでは\n"
	.string "{JPN}ラジオが へんな でんぱを\nひろうんだ$"

SSAqua_B1F_EventScript_Ricky::
	trainerbattle_single TRAINER_RICKY SSAqua_B1F_Text_SchoolboyRickySeen, SSAqua_B1F_Text_SchoolboyRickyBeaten
	msgbox SSAqua_B1F_Text_SchoolboyRickyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyRickySeen:
	.string "{JPN}アルフのいせきには\n"
	.string "{JPN}ふしぎな いしの パネルが\nあるんだ$"

SSAqua_B1F_Text_SchoolboyRickyBeaten:
	.string "{JPN}やられちゃった!$"

SSAqua_B1F_Text_SchoolboyRickyAfter:
	.string "{JPN}あの いしの パネルは\n"
	.string "{JPN}4つ あるって よんだよ$"

