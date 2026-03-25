Route47_MapScripts::
	.byte 0


Route47_EventScript_Hiker::
	trainerbattle_single TRAINER_DEVIN, Route47_Text_HikerSeen, Route47_Text_HikerBeaten
	msgbox Route47_Text_HikerAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_HikerSeen::
	.string "{JPN}ひとを したうのは...\n"
	.string "{JPN}そういうものさ.\p"
	.string "{JPN}でも しょうぶは しょうぶ \n"
	.string "{JPN}いくぞ!$"

Route47_Text_HikerBeaten::
	.string "{JPN}わはは!$"

Route47_Text_HikerAfter::
	.string "{JPN}しょうぶの あとは いつも\n"
	.string "{JPN}わらって わかれるもんさ!$"

Route47_EventScript_Camper::
	trainerbattle_single TRAINER_GRANT, Route47_Text_CamperSeen, Route47_Text_CamperBeaten
	msgbox Route47_Text_CamperAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_CamperSeen::
	.string "{JPN}おおぜいの ひとは にがてだから\n"
	.string "{JPN}ここで ポケモンと\l"
	.string "{JPN}キャンプしてるんだ!$"

Route47_Text_CamperBeaten::
	.string "{JPN}やまの もっと おくへ\n"
	.string "{JPN}いったほうが よさそうだな...$"

Route47_Text_CamperAfter::
	.string "{JPN}じゃあね!$"

Route47_EventScript_Thom::
	trainerbattle_double TRAINER_THOM_AND_KAE, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Kae::
	trainerbattle_double TRAINER_THOM_AND_KAE, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple1Seen::
	.string "{JPN}トム: 1たす1は 2だ.でも ぼくらが\n"
	.string "{JPN}ふたりで いると もっと\l"
	.string "{JPN}つよくなる!\p"
	.string "{JPN}カエ: わたしたちは ただの\n"
	.string "{JPN}つまらない ペアじゃないの!$"

Route47_Text_Couple1Beaten::
	.string "{JPN}トム: よそうと ちがったな.\l"
	.string "{JPN}カエ: あなたも かわってるわね!$"

Route47_Text_Couple1After1::
	.string "{JPN}トム: きみの ちからは\n"
	.string "{JPN}よそくできないね!$"

Route47_Text_Couple1After2::
	.string "{JPN}カエ: ふつうの ひとりぼっちの\n"
	.string "{JPN}トレーナーだと おもってた.まちがいだったわ!$"

Route47_EventScript_Duff::
	trainerbattle_double TRAINER_DUFF_AND_EDA, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple2After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Eda::
	trainerbattle_double TRAINER_DUFF_AND_EDA, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox Route47_Text_Couple2After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple2Seen::
	.string "{JPN}ダフ: かのじょを まもってると\n"
	.string "{JPN}こころが はずむよ!\p"
	.string "{JPN}エダ: かれへの きもちは\n"
	.string "{JPN}うみのように ひろくて\l"
	.string "{JPN}ふかいの!$"

Route47_Text_Couple2Beaten::
	.string "{JPN}ダフ: きみには かなわなかった...\l"
	.string "{JPN}エダ: あなたって すごいのね...$"

Route47_Text_Couple2After1::
	.string "{JPN}ダフ: すばらしい しょうぶを\n"
	.string "{JPN}ありがとう! じゃあね!$"

Route47_Text_Couple2After2::
	.string "{JPN}エダ: あなたも すてきな パートナーを\n"
	.string "{JPN}みつけたほうが いいわよ!$"

Route47_EventScript_Sage::
	lock
	faceplayer
	msgbox EmbeddedTower_Text_OldManIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

EmbeddedTower_Text_OldManIntro:
	.string "{JPN}やーどーも！\p"
	.string "{JPN}このあなのむこうに\n"
	.string "{JPN}そらをつらぬくきょだいなとうが\l"
	.string "{JPN}あったといわれているんですよー\p"
	.string "{JPN}ちょっとかわったかたちの\n"
	.string "{JPN}とうだったらしくてですねー\p"
	.string "{JPN}はんぶんはこのがけのなかに\n"
	.string "{JPN}つくられていたみたいなんですねー\p"
	.string "{JPN}そらへのびているだけでなく\n"
	.string "{JPN}ちかにもながーいとうだったと！\p"
	.string "{JPN}しかもうみのなかまで\n"
	.string "{JPN}つながっていたといわれてるんです！\p"
	.string "{JPN}つまりそらとりくとうみを\n"
	.string "{JPN}むすびつけていた..\l"
	.string "{JPN}そういういせきなんですねー\p"
	.string "{JPN}いまではほとんどくずれてしまって\n"
	.string "{JPN}とうにはいるためのいりぐちと\l"
	.string "{JPN}ふしぎなもようがえがかれた\l"
	.string "{JPN}とうのちゅうおうぶだけが\l"
	.string "{JPN}のこっているだけなんですけどねー$"
Route47_EventScript_Item_Pearl::
    finditem ITEM_PEARL
    end

Route47_EventScript_Item_Revive::
    finditem ITEM_REVIVE
    end

Route47_EventScript_Item_WhiteFlute::
    finditem ITEM_WHITE_FLUTE
    end

Route47_EventScript_Item_Stardust::
	finditem ITEM_STARDUST
	end

Route47_EventScript_Item_LuckyPunch::
	finditem ITEM_LUCKY_PUNCH
	end

Route47_EventScript_Chinchou::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHINCHOU, CRY_MODE_NORMAL
	msgbox Route47_Text_Chinchou, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route47_Text_Chinchou:
	.string "{JPN}チョンチー: チョウ!$"
