SSAqua_RoomSW_MapScripts::
	.byte 0

SSAqua_RoomSW_EventScript_Cassie::
	trainerbattle_single TRAINER_CASSIE SSAqua_RoomSW_Text_BeautyCassieSeen, SSAqua_RoomSW_Text_BeautyCassieBeaten
	msgbox SSAqua_RoomSW_Text_BeautyCassieAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_EventScript_Clyde::
	trainerbattle_single TRAINER_CLYDE SSAqua_RoomSW_Text_GuitaristClydeSeen, SSAqua_RoomSW_Text_GuitaristClydeBeaten
	msgbox SSAqua_RoomSW_Text_GuitaristClydeAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_Text_BeautyCassieSeen:
    .string "{JPN}わたし つらいことを\n"
	.string "{JPN}わすれたいの\lいっしょに たたかいましょう$"

SSAqua_RoomSW_Text_BeautyCassieBeaten:
    .string "{JPN}わたしのこころが\nないている...$"
SSAqua_RoomSW_Text_BeautyCassieAfterBattle:
    .string "{JPN}りょこうは しつれんを\n"
	.string "{JPN}なおすのに いちばんよ\p"
    .string "{JPN}でも こうそくせんでの\n"
	.string "{JPN}たびは みじかすぎるわ$"

SSAqua_RoomSW_Text_GuitaristClydeSeen:
    .string "{JPN}コガネシティの ラジオとうで\n"
	.string "{JPN}じぶんの うたの オーディション\nうけるんだ$"

SSAqua_RoomSW_Text_GuitaristClydeBeaten:
    .string "{JPN}うわあ! かんぜんに\nちょうしが くるった!$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattleMobile:
    .string "{JPN}バトルタワーで\n"
	.string "{JPN}デビューするつもり\n"
	.string "{JPN}だったのに...\p"
	.string "{JPN}クチバにもどって\nしゅぎょうを\nやりなおそう...$"
SSAqua_RoomSW_Text_GuitaristClydeAfterBattle:
    .string "{JPN}そうそう ラジオとうといえば\n"
	.string "{JPN}こんしゅうの らっきーなんばーは\nなんばんだっけ?$"
