.set LOCALID_CELADON_ERIKA, 15

CeladonCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_EventScript_CityEnter
	.byte 0

CeladonCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CELADON_CITY
	end

CeladonCity_EventScript_Erika::
    lock
    faceplayer
    msgbox CeladonCity_Text_Erika, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_FOUNTAIN_ERIKA
    removeobject LOCALID_CELADON_ERIKA
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_ERIKA
    release
    end

CeladonCity_Text_Erika:
    .string "{JPN}あら {PLAYER}.\n"
	.string "{JPN}きょうも ふんすい きれいね.\p"
	.string "{JPN}また バトル したいなら\n"
	.string "{JPN}かくとうどうじょうで まってるわ.$"

CeladonCity_EventScript_Fatman::
	msgbox CeladonCity_Text_Fisher, MSGBOX_NPC
	end
CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeladonCity_EventScript_Teacher1::
	msgbox CeladonCity_Text_Teacher1, MSGBOX_NPC
	end

CeladonCity_EventScript_GrimerGramps::
	msgbox CeladonCity_Text_Gramps1, MSGBOX_NPC
	end

CeladonCity_EventScript_CreepGramps::
	msgbox CeladonCity_Text_Gramps2, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster::
	msgbox CeladonCity_Text_Youngster1, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster2::
	msgbox CeladonCity_Text_Youngster2, MSGBOX_NPC
	end

CeladonCity_EventScript_Teacher2::
	msgbox CeladonCity_Text_Teacher2, MSGBOX_NPC
	end

CeladonCity_EventScript_Lass::
	msgbox CeladonCity_Text_Lass, MSGBOX_NPC
	end

CeladonCity_Text_Fisher:
	.string "{JPN}このニョロボンは\n"
	.string "{JPN}ぼくの パートナーだ.\p"
	.string "{JPN}かえるポケモンに\nしんかするんだろうか.$"

CeladonCity_Text_Poliwrath:
	.string "{JPN}ニョロボン: ケロ!$"

CeladonCity_Text_Teacher1:
	.string "{JPN}また スロットマシンで\n"
	.string "{JPN}まけちゃった...\p"
	.string "{JPN}わたしたち おんなのこも\nいまは スロットを やるのよ\pあなたも ためしてみたら?$"

CeladonCity_Text_Gramps1:
	.string "{JPN}さいきん ベトベターが\n"
	.string "{JPN}あらわれておるんじゃ\p"
	.string "{JPN}いえの まえの いけが\n"
	.string "{JPN}みえるじゃろう?\l"
	.string "{JPN}あそこに ベトベターが\nすんでおるんじゃ\pどこから きたのかのう?\nこれは しんこくな もんだい\nじゃよ...$"
CeladonCity_Text_Gramps2:
	.string "{JPN}にひひ! このジムは サイコーじゃ!\n"
	.string "{JPN}おんなのこだけが はいれるんじゃ!$"

CeladonCity_Text_Youngster1:
	.string "{JPN}ひみつを おしえてあげようか?\p"
	.string "{JPN}タマムシマンションには\n"
	.string "{JPN}うらぐちが あるんだ.$"

CeladonCity_Text_Youngster2:
	.string "{JPN}レストランで たいしょく\n"
	.string "{JPN}たいかいを やってるんだ\p"
	.string "{JPN}みてるだけで おなかが\n"
	.string "{JPN}いっぱいに なっちゃうよ...$"
CeladonCity_Text_Teacher2:
	.string "{JPN}タマムシデパートは\n"
	.string "{JPN}しょうひんの しゅるいも\n"
	.string "{JPN}かずも いちばんなの\p"
	.string "{JPN}そこで てにはいらない\n"
	.string "{JPN}ものは どこにも ないわ\pあら... わたし てんいんさん\nみたいね$"
CeladonCity_Text_Lass:
	.string "{JPN}あるいてるとき あしもとを\n"
	.string "{JPN}みてたら めが まわっちゃった.$"

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	msgbox CeladonGym_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_StoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips::
	msgbox CeladonCity_Text_TrainerTips, MSGBOX_SIGN
	end

CeladonCity_Text_Sign:
	.string "{JPN}タマムシシティ\p"
	.string "{JPN}にじいろの ゆめの まち$"

CeladonGym_Text_Sign:
	.string "{JPN}タマムシシティ ポケモンジム\n"
	.string "{JPN}リーダー: エリカ\p"
	.string "{JPN}しぜんを あいする おひめさま$"

CeladonCity_Text_DeptStoreSign:
	.string "{JPN}ほしいもの みつかる\n"
	.string "{JPN}タマムシ デパート!$"

CeladonCity_Text_MansionSign:
	.string "{JPN}タマムシマンション$"

CeladonCity_Text_GameCornerSign:
	.string "{JPN}みんなの あそびば\n"
	.string "{JPN}タマムシ ゲームコーナー$"

CeladonCity_Text_TrainerTips:
	.string "{JPN}トレーナーのこころえ\p"
	.string "{JPN}ディフェンダーは ほのおや\n"
	.string "{JPN}みずなど とくしゅこうげきから\n"
	.string "{JPN}ポケモンを まもるぞ!\p"
	.string "{JPN}アイテムは タマムシデパートで!$"
	.string ""
