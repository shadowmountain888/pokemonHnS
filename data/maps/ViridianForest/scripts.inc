.set LOCALID_VIRIDIAN_BUGSY, 16

ViridianForest_MapScripts::
	.byte 0

ViridianForest_EventScript_Bugsy::
	lock
	faceplayer
	msgbox ViridianForest_Text_Bugsy, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_VIRIDIAN_BUGSY
	removeobject LOCALID_VIRIDIAN_BUGSY
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_BUGSY
	release
	end

ViridianForest_Text_Bugsy:
	.string "{JPN}ツクシ: ぼくは むしタイプの\n"
	.string "{JPN}ポケモンを さがしに カントーに\l"
	.string "{JPN}きたんだ! つよい むしタイプの\l"
	.string "{JPN}トレーナーに なるためにね!\p"
    .string "{JPN}また しょうぶする きが あったら\n"
	.string "{JPN}ヤマブキシティの どうじょうで\lまってるよ!$"

ViridianForest_EventScript_MaxPotion::
    finditem ITEM_MAX_POTION
    end

ViridianForest_EventScript_DireHit::
    finditem ITEM_DIRE_HIT
    end

ViridianForest_EventScript_Elixir::
    finditem ITEM_ELIXIR
    end

ViridianForest_EventScript_Revive::
    finditem ITEM_REVIVE
    end

ViridianForest_EventScript_FullRestore::
    finditem ITEM_FULL_RESTORE
    end

ViridianForest_EventScript_MaxEther::
    finditem ITEM_MAX_ETHER
    end

ViridianForest_EventScript_FullHeal::
    finditem ITEM_FULL_HEAL
    end
