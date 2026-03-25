Route46_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route46_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route46_EventScript_Bailey::
	trainerbattle_single TRAINER_BAILEY, Route46_Text_HikerBaileySeen, Route46_Text_HikerBaileyBeaten
	msgbox Route46_Text_HikerBaileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Ted::
	trainerbattle_single TRAINER_TED, Route46_Text_CamperTedSeen, Route46_Text_CamperTedBeaten
	msgbox Route46_Text_CamperTedAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Erin::
	trainerbattle_single TRAINER_ERIN, Route46_Text_PicnickerErinSeen, Route46_Text_PicnickerErinBeaten
	msgbox Route46_Text_PicnickerErinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Sign::
	lock
	msgbox Route46_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route46_EventScript_Item_Revive::
	finditem ITEM_REVIVE
	end

Route46_Text_HikerBaileySeen:
	.string "{JPN}よし!やまの ポケモンの\n"
	.string "{JPN}ちからを みせてやるぜ!$"

Route46_Text_HikerBaileyBeaten:
	.string "{JPN}まいった! きみの ちからを\n"
	.string "{JPN}みせつけられたよ!$"

Route46_Text_HikerBaileyAfterBattle:
	.string "{JPN}おわりだ.きにしないさ.\n"
	.string "{JPN}われら やまおとこは そういう\nものだからな.$"

Route46_Text_CamperTedSeen:
	.string "{JPN}おれも ポケモンを そだててる!\p"
	.string "{JPN}\nしょうぶしてくれるかい?$"

Route46_Text_CamperTedBeaten:
	.string "{JPN}な...なんだって...?$"
Route46_Text_CamperTedAfterBattle:
	.string "{JPN}さいぜんを つくしたけど\n"
	.string "{JPN}ちからおよばなかった.\p"
	.string "{JPN}\nいいわけなし まけをみとめる.$"

Route46_Text_PicnickerErinSeen:
	.string "{JPN}わたしも ポケモンを そだててる!\p"
	.string "{JPN}\nしょうぶしてくれる?$"

Route46_Text_PicnickerErinBeaten:
	.string "{JPN}ああ もう!$"

Route46_Text_PicnickerErinAfterBattle:
	.string "{JPN}いろんな ジムに いったけど\n"
	.string "{JPN}コガネシティの ジムが いちばん!\p"
	.string "{JPN}\nきれいな はなで いっぱいなの!$"

Route46_Text_PicnickerErin2Beaten:
	.string "{JPN}あーあ... いつも\n"
	.string "{JPN}まけちゃうなあ!\p"
	.string "{JPN}もっと がんばらなくちゃ!\n"
	.string "{JPN}でも なんども バトル\n"
	.string "{JPN}してくれて ありがとう.\p"
	.string "{JPN}このまえの おれいを\nどうぞ.$"

Route46_Text_Sign:
	.string "{JPN}ここは46ばんどうろ\n"
	.string "{JPN}このさきマウンテンロード$"