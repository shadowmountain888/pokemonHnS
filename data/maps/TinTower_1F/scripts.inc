TinTower_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TinTower_OnTransition
	.byte 0

TinTower_OnTransition::
	setescapewarp MAP_BELLCHIME_TRAIL, 35, 42
	end

TinTower_1F_EventScript_SageA::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageA_Hooh
	msgbox TinTower_1F_Sage4_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageA_Hooh::
	msgbox TinTower_1F_Sage4_Text1, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageB_Hooh
	msgbox TinTower_1F_Sage2_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB_Hooh::
	msgbox TinTower_1F_Sage1_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageC_Hooh
	msgbox TinTower_1F_Sage6_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC_Hooh::
	msgbox TinTower_1F_Sage3_Text, MSGBOX_DEFAULT
	closemessage
	release
	end


TinTower_1F_Sage1_Text:
	.string "{JPN}ホウオウをよびもどすため\nこれまでなんにんものにんげんが\l"
	.string "{JPN}にじいろのはねをてにして\lこのとうをのぼっていきました\p"
	.string "{JPN}しかしまだだれも\nホウオウをよびよせることが\l"
	.string "{JPN}できずにいるのです...\p"
	.string "{JPN}にじいろのはねは\nこのとうをのぼるための\lつうこうてがたのようなもの\p"
	.string "{JPN}ホウオウがほんとうに\nまちのぞんでいるのは\lにんげんとポケモンとの"
	.string "{JPN}\lめにみえないきずな...\p"
	.string "{JPN}いやきずなをとりもどすに\nふさわしいじんぶつ\l"
	.string "{JPN}なのではないでしょうか...\p$"

TinTower_1F_Sage2_Text:
	.string "{JPN}このとうにいたポケモン\nすなわちホウオウは\lそらたかくとびたち\l"
	.string "{JPN}にどとおりてこなくなりました\p"
	.string "{JPN}もしポケモンとふかいきずなを\nむすべるにんげんが\l"
	.string "{JPN}ホウオウにゆかりのあるものを\lもってくれば\p"
	.string "{JPN}ホウオウはさそわれて\nおりてくるかもしれません...\p$"

TinTower_1F_Sage3_Text:
	.string "{JPN}ふたつの とうは ポケモンと\n"
	.string "{JPN}ひとびとの ゆうじょうと\p"
	.string "{JPN}きぼうを はぐくむために\n"
	.string "{JPN}たてられたと いわれておる.\p"
	.string "{JPN}700ねんまえの ことじゃが\nその りそうは いまも\pたいせつなのじゃ.$"

TinTower_1F_Sage4_Text1:
	.string "{JPN}ホウオウが この スズのとうに\n"
	.string "{JPN}まいおりてきたようじゃ!$"

TinTower_1F_Sage4_Text2:
	.string "{JPN}でんせつの ポケモンは\n"
	.string "{JPN}みっつの ちからを\l"
	.string "{JPN}あらわすという...\p"
	.string "{JPN}とうに おちた いかずち\n"
	.string "{JPN}とうを やいた ほのお\pそして ひを けした\nあめ...$"
TinTower_1F_Sage6_Text2:
	.string "{JPN}でんせつの ポケモンの なかでも\n"
	.string "{JPN}スイクンが いちばん\p"
	.string "{JPN}ホウオウに ちかいと\n"
	.string "{JPN}いわれておる.\p"
	.string "{JPN}アンノーンという ポケモンとも\n"
	.string "{JPN}なにか かんけいが\pあるらしいのじゃ.\nアンノーンは スイクンと\pきょうりょくてきな きずなを\nむすんでおるに ちがいない.$"

TinTower_1F_EusineHoOh_Text:
	.string "{JPN}マツバ: スズのとうは\nひととポケモンのきずなを\lたしかめるところだ\p"
	.string "{JPN}きみにはうまれながらにして\nそのそしつがあったのかも...\p"
	.string "{JPN}ぼくとでんわばんごうを\nこうかんしないか?\p"
	.string "{JPN}きみとポケモンのきずなを\nもっとみてみたいんだ$"

TinTower_1F_EusineSuicune_Text:
	.string "{JPN}ミナキ: すげえ! すげすぎる!\n"
	.string "{JPN}こんな すばらしい たたかいは\p"
	.string "{JPN}みたことがない.\n"
	.string "{JPN}ほんとうに かんどうしたよ.\p"
	.string "{JPN}スイクンも つよかったが\n"
	.string "{JPN}{PLAYER}の ほうが\p"
	.string "{JPN}もっと すごかった.\n"
	.string "{JPN}スイクンの しんぴの ちからは\p"
	.string "{JPN}にじいろの ポケモンを\n"
	.string "{JPN}よびだすと きいておる.\p"
	.string "{JPN}もしかしたら きょうの\n"
	.string "{JPN}できごとで そのポケモンが\p"
	.string "{JPN}あらわれるかもしれん.\nでんせつを もっと\pけんきゅうしてみるよ.\nすばらしい たたかいを\pみせてくれて ありがとう.\nそれじゃあ {PLAYER}!$"
