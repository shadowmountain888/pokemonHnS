CeladonCity_DepartmentStore_3F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept3_EventScript_Youngster::
	msgbox CeladonDeptStore3F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept3_EventScript_Gbakid1::
	msgbox CeladonDeptStore3F_Text_GameboyKid1, MSGBOX_NPC
	end
CeladonDept3_EventScript_Gbakid2::
	msgbox CeladonDeptStore3F_Text_GameboyKid2, MSGBOX_NPC
	end
CeladonDept3_EventScript_SuperNerd::
	msgbox CeladonDeptStore3F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept3_EventScript_Directory::
	msgbox CeladonDeptStore3F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore3F_Text_Youngster:
	.string "{JPN}このわざマシンを\n"
	.string "{JPN}どのポケモンに\lつかおうか\lまよっちゃうなあ...$"
CeladonDeptStore3F_Text_GameboyKid1:
	.string "{JPN}あー! アップグレードを\n"
	.string "{JPN}はずすのを わすれて\lポケモンを こうかんしちゃった!$"

CeladonDeptStore3F_Text_GameboyKid2:
	.string "{JPN}やったー!ついに\n"
	.string "{JPN}ポリゴンを\l"
	.string "{JPN}てにいれるぞ!\p"
	.string "{JPN}スロットがへたで\n"
	.string "{JPN}コインがぜんぜん\l"
	.string "{JPN}たまらなかったんだ...\p"
	.string "{JPN}...あれ?\pこうかんしたポリゴンが\nちがうポケモンに\lなっちゃった!$"

CeladonDeptStore3F_Text_SuperNerd:
	.string "{JPN}わざマシンショップでは\nめずらしい わざが うってるよ.$"

CeladonDeptStore3F_Text_Directory:
	.string "{JPN}3F: わざマシンショップ\p"
	.string "{JPN}ポケモンを つよくしよう!$"

