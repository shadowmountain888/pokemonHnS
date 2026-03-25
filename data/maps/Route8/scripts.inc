Route8_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route8_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route8_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route8_Text_BikerDwayneSeen, Route8_Text_BikerDwayneBeaten
	msgbox Route8_Text_BikerDwayneAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Harris::
	trainerbattle_single TRAINER_HARRIS, Route8_Text_BikerHarrisSeen, Route8_Text_BikerHarrisBeaten
	msgbox Route8_Text_BikerHarrisAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Zeke::
	trainerbattle_single TRAINER_ZEKE, Route8_Text_BikerZekeSeen, Route8_Text_BikerZekeBeaten
	msgbox Route8_Text_BikerZekeAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Sam::
	trainerbattle_single TRAINER_SAM, Route8_Text_SupernerdSamSeen, Route8_Text_SupernerdSamBeaten
	msgbox Route8_Text_SupernerdSamAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Tom::
	trainerbattle_single TRAINER_TOM, Route8_Text_SupernerdTomSeen, Route8_Text_SupernerdTomBeaten
	msgbox Route8_Text_SupernerdTomAfter, MSGBOX_AUTOCLOSE
	end

Route8_Text_BikerDwayneSeen:
	.string "{JPN}おれたちは カントーポケモン\n"
	.string "{JPN}れんごうの トレーナーぐんだん\n"
	.string "{JPN}だぜ!\pおまえを しゃりんの したに\nおいこんでやるぜ!$"

Route8_Text_BikerDwayneBeaten:
	.string "{JPN}す すまねえ!$"

Route8_Text_BikerDwayneAfter:
	.string "{JPN}カントーポケモンれんごうは\n"
	.string "{JPN}ぜったいに たおれねえぜ!$"

Route8_Text_BikerHarrisSeen:
	.string "{JPN}けいさつが おれたちの\n"
	.string "{JPN}ちかつうろを とじやがった!\p"
	.string "{JPN}ほんとに むかつくぜ!$"

Route8_Text_BikerHarrisBeaten:
	.string "{JPN}ゆ ゆるしてくれ!$"

Route8_Text_BikerHarrisAfter:
	.string "{JPN}ジョウトの がきに\n"
	.string "{JPN}やられちまった...$"
Route8_Text_BikerZekeSeen:
	.string "{JPN}おれたちは カントーポケモン\n"
	.string "{JPN}れんごうだ!\n"
	.string "{JPN}よろしくな!$"

Route8_Text_BikerZekeBeaten:
	.string "{JPN}うわあ! すまねえ!$"

Route8_Text_BikerZekeAfter:
	.string "{JPN}もう だれにも めいわく\n"
	.string "{JPN}かけないようにする...$"
Route8_Text_SupernerdSamSeen:
	.string "{JPN}リニアは どうやって\nうごくんだろう?$"

Route8_Text_SupernerdSamBeaten:
	.string "{JPN}リニアを みてみたいん\n"
	.string "{JPN}だよな...$"
Route8_Text_SupernerdSamAfter:
	.string "{JPN}じしゃくの ちからって\nすごいよね!$"

Route8_Text_SupernerdTomSeen:
	.string "{JPN}ふむ... きみは ジムバッジを\nたくさん もってるね$"
Route8_Text_SupernerdTomBeaten:
	.string "{JPN}やっぱりな... きみは\nつよいよ!$"
Route8_Text_SupernerdTomAfter:
	.string "{JPN}ジムバッジは バトルで\n"
	.string "{JPN}ゆうりに なるんだよ.$"

Route8_Text_LockedDoor:
	.string "{JPN}かぎが かかっている...$"
Route8_Text_UndergroundPathSign:
	.string "{JPN}チラシがはがされている！\n"
	.string "{JPN}よめない..$"