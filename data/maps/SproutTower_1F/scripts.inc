SproutTower_1F_MapScripts::
	.byte 0

SproutTower_1F_EventScript_SageChow::
	trainerbattle_single TRAINER_CHOW, SproutTower_Text_SageChow_Seen, SproutTower_Text_SageChow_Beaten
	msgbox SproutTower_Text_SageChow_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_1F_EventScript_Sage1::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage1, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Sage2::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage2, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Granny::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Teacher::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_ItemParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

SproutTower_Text_SageChow_Seen:
	.string "{JPN}わたしたちは このとうを\n"
	.string "{JPN}まもっています.\p"
	.string "{JPN}ここで すべてのポケモンを\nたたえ かんしゃを\nささげるのです.$"

SproutTower_Text_SageChow_Beaten:
	.string "{JPN}あ ありがとう\nございます!$"

SproutTower_Text_SageChow_AfterBattle:
	.string "{JPN}すべての いきものは\n"
	.string "{JPN}きょうりょくして\n"
	.string "{JPN}ともにいきています.\p"
	.string "{JPN}わたしたちは いつも\nそのことに かんしゃ\nしなければなりません.$"

SproutTower_Text_1F_Sage1:
	.string "{JPN}てっぺんまで たどりつけば\n"
	.string "{JPN}ひでんマシンが てにはいる\nでしょう.$"

SproutTower_Text_1F_Sage2:
	.string "{JPN}スプラウトタワーは\n"
	.string "{JPN}むかしから ポケモンの\nしゅぎょうのばとして\nたてられました.$"

SproutTower_Text_1F_Granny:
	.string "{JPN}100フィートを こえる\n"
	.string "{JPN}マダツボミ...\p"
	.string "{JPN}それが ここの ちゅうしんの\n"
	.string "{JPN}はしらに なったと いわれて\nいるんじゃよ$"

SproutTower_Text_1F_Teacher:
	.string "{JPN}はしらが ゆれているのが\n"
	.string "{JPN}みえますか?\pうえのかいで だれかが\nしゅぎょうをしているのです.$"

SproutTower_Text_1F_Statue:
	.string "{JPN}ポケモンの ぞう...\p"
	.string "{JPN}とても りっぱに みえる$"
