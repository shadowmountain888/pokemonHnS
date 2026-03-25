.set LOCALID_FOSSIL_SCIENTIST, 3

RustboroCity_DevonCorp_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_2F_OnTransition
	.byte 0

RustboroCity_DevonCorp_2F_OnTransition:
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	end

RustboroCity_DevonCorp_2F_EventScript_SetFossilReady::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
	return

RustboroCity_DevonCorp_2F_EventScript_TalkToPokemonScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_BallScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls::
	msgbox RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_PokenavScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_DevonCorp_2F_EventScript_HasPokenav
	msgbox RustboroCity_DevonCorp_2F_Text_IMadePokenav, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_HasPokenav::
	msgbox RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilScientist::
	lock
	faceplayer
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, RustboroCity_DevonCorp_2F_EventScript_FossilMonReady
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_StillRegenerating
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeHelixFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeDomeFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeOldAmber
	release
	end

@ This whole section has needless duplication and could be condensed considerably
RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil::
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_ROOT_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
	release
	end

RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil::
	bufferitemname STR_VAR_1, ITEM_CLAW_FOSSIL
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_CLAW_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
	release
	end

RustboroCity_DevonCorp_2F_EventScript_NoticeHelixFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	goto RustboroCity_DevonCorp_2F_EventScript_GiveHelixFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveHelixFossil::
	bufferitemname STR_VAR_1, ITEM_HELIX_FOSSIL
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_HELIX_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 3
	release
	end

RustboroCity_DevonCorp_2F_EventScript_NoticeDomeFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	goto RustboroCity_DevonCorp_2F_EventScript_GiveDomeFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveDomeFossil::
	bufferitemname STR_VAR_1, ITEM_DOME_FOSSIL
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_DOME_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_NoticeOldAmber::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	goto RustboroCity_DevonCorp_2F_EventScript_GiveOldAmber
	end

RustboroCity_DevonCorp_2F_EventScript_GiveOldAmber::
	bufferitemname STR_VAR_1, ITEM_OLD_AMBER
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_OLD_AMBER
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 5
	release
	end

RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil::
	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil2::
	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo2, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_StillRegenerating::
	msgbox RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilMonReady::
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 1, RustboroCity_DevonCorp_2F_EventScript_LileepReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 2, RustboroCity_DevonCorp_2F_EventScript_AnorithReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 3, RustboroCity_DevonCorp_2F_EventScript_OmanyteReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 4, RustboroCity_DevonCorp_2F_EventScript_KabutoReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 5, RustboroCity_DevonCorp_2F_EventScript_AeroReady
	end

RustboroCity_DevonCorp_2F_EventScript_LileepReady::
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep
	end

RustboroCity_DevonCorp_2F_EventScript_AnorithReady::
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith
	end

RustboroCity_DevonCorp_2F_EventScript_OmanyteReady::
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveOmanyte
	end

RustboroCity_DevonCorp_2F_EventScript_KabutoReady::
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveKabuto
	end

RustboroCity_DevonCorp_2F_EventScript_AeroReady::
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveAero
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LILEEP
	givemon SPECIES_LILEEP, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
	end
	
RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC::
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
	return

RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ANORITH
	givemon SPECIES_ANORITH, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
	end

RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC::
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_ANORITH
	return

RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveOmanyte::
	setvar VAR_TEMP_1, SPECIES_OMANYTE
	givemon SPECIES_OMANYTE, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveOmanyteParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveOmanytePC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveOmanyteParty::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedOmanyteFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ReceiveOmanyteParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingOmanyte
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingOmanyte
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveOmanyteParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingOmanyte
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveOmanytePC::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedOmanyteFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ReceiveOmanytePC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferOmanyteToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferOmanyteToPC
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveOmanytePC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferOmanyteToPC
	end
	
RustboroCity_DevonCorp_2F_EventScript_TransferOmanyteToPC::
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingOmanyte
	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedOmanyteFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
	return

RustboroCity_DevonCorp_2F_EventScript_FinishReceivingOmanyte::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveKabuto::
	setvar VAR_TEMP_1, SPECIES_KABUTO
	givemon SPECIES_KABUTO, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveKabutoParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveKabutoPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveKabutoParty::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedKabutoFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ReceiveKabutoParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingKabuto
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingKabuto
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveKabutoParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingKabuto
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveKabutoPC::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedKabutoFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ReceiveKabutoPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferKabutoToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferKabutoToPC
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveKabutoPC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferKabutoToPC
	end
	
RustboroCity_DevonCorp_2F_EventScript_TransferKabutoToPC::
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingKabuto
	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedKabutoFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
	return

RustboroCity_DevonCorp_2F_EventScript_FinishReceivingKabuto::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAero::
	setvar VAR_TEMP_1, SPECIES_AERODACTYL
	givemon SPECIES_AERODACTYL, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveAeroParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveAeroPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAeroParty::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAeroFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ReceiveAeroParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAero
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAero
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAeroParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAero
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAeroPC::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAeroFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ReceiveAeroPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferAeroToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferAeroToPC
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveAeroPC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferAeroToPC
	end
	
RustboroCity_DevonCorp_2F_EventScript_TransferAeroToPC::
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAero
	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedAeroFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
	return

RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAero::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end


RustboroCity_DevonCorp_2F_EventScript_ChooseFossil::
	message RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne
	waitmessage
	multichoice 17, 0, MULTI_FOSSIL, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil
	case 1, RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil
	case 2, RustboroCity_DevonCorp_2F_EventScript_ChooseHelixFossil
	case 3, RustboroCity_DevonCorp_2F_EventScript_ChooseDomeFossil
	case 4, RustboroCity_DevonCorp_2F_EventScript_ChooseOldAmber
	case 5, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil::
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil2
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil::
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil2
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseHelixFossil::
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_GiveHelixFossil
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil2
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseDomeFossil::
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_GiveDomeFossil
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil2
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseOldAmber::
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_GiveOldAmber
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil2
	end

RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect::
	release
	end

RustboroCity_DevonCorp_2F_EventScript_MatchCallScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_ge VAR_GARBAGEVAR, 6, RustboroCity_DevonCorp_2F_EventScript_WorkOnNext
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_WorkOnNext::
	msgbox RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon:
	.string "{JPN}ポケモンと おはなしする\n"
	.string "{JPN}そうちを かいはつしてるんだ.\p"
	.string "{JPN}でも なかなか\nうまくいかなくて...$"
RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls:
	.string "{JPN}あたらしい しゅるいの\n"
	.string "{JPN}モンスターボールを\l"
	.string "{JPN}かいはつしてるんだ...\pでも あまり\nしんてんがなくて...$"
RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls:
	.string "{JPN}ついに あたらしい しゅるいの\n"
	.string "{JPN}モンスターボールが できました!\p"
	.string "{JPN}リピートボールは いちど\n"
	.string "{JPN}つかまえた ポケモンを\l"
	.string "{JPN}つかまえやすく します.\p"
	.string "{JPN}タイマーボールは たたかいが\n"
	.string "{JPN}ながびくほど ポケモンを\l"
	.string "{JPN}つかまえやすく なります.\p"
	.string "{JPN}どちらも デボンコーポレーションが\nじまんを もって かいはつ しました.\pぜひ つかって みて ください!$"

RustboroCity_DevonCorp_2F_Text_IMadePokenav:
	.string "{JPN}わたしが ポケナビを つくりました!\p"
	.string "{JPN}エンジニアとして これほど\n"
	.string "{JPN}すばらしいものが つくれて\lしあわせです!$"

RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav:
	.string "{JPN}おお! それは ポケナビですね!\p"
	.string "{JPN}しゃちょうの ポケモンの こころを\n"
	.string "{JPN}しりたい という おもいから\l"
	.string "{JPN}うまれた ものです.\p"
	.string "{JPN}きのうについて くわしく\n"
	.string "{JPN}せつめい しましょうか?\p"
	.string "{JPN}いえいえ.じっさいに ポケナビを\n"
	.string "{JPN}つかって みれば わかりますよ.$"
	.string ""

RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams:
	.string "{JPN}ポケモンの ゆめを\n"
	.string "{JPN}がめんに うつしだす\l"
	.string "{JPN}そうちを かいはつしてるんだ...\p"
	.string "{JPN}でも うまくいってないんだよ.$"

RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils:
	.string "{JPN}かせきから ポケモンを\n"
	.string "{JPN}ふっかつさせる そうちを\l"
	.string "{JPN}かいはつしてるんだ...\pそれで ついに うまくいったよ!$"

RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife:
	.string "{JPN}まてよ! きみの もってるもの...\n"
	.string "{JPN}それって ポケモンの かせき?\p"
	.string "{JPN}その ポケモンを\n"
	.string "{JPN}ふっかつ させてみない?\p"
	.string "{JPN}ぼくが あたらしく かいはつした\n"
	.string "{JPN}かせきふっかつそうちで できるよ.$"

RustboroCity_DevonCorp_2F_Text_OhIsThatSo:
	.string "{JPN}そう なのですか?\n"
	.string "{JPN}わたしの ぎじゅつりょくは\l"
	.string "{JPN}ばつぐんなのですよ.$"

RustboroCity_DevonCorp_2F_Text_OhIsThatSo2:
	.string "{JPN}おや  その かせきは\n"
	.string "{JPN}もって いませんね.\lみつけたら きて ください.$"

RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne:
	.string "{JPN}おや  これは おどろきです!\n"
	.string "{JPN}ふくすうの かせきを もって\l"
	.string "{JPN}いるのですね?\p"
	.string "{JPN}ざんねんですが わたしの きかいは\n"
	.string "{JPN}いちどに ひとつの ポケモンしか\l"
	.string "{JPN}ふっかつ できません.\pどの かせきを ふっかつ\nさせますか?$"

RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher:
	.string "{JPN}すばらしい!\n"
	.string "{JPN}すぐに はじめましょう.\p"
	.string "{JPN}{PLAYER}は {STR_VAR_1}を\n"
	.string "{JPN}いせき けんきゅういんに わたした.$"

RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime:
	.string "{JPN}ぼくが つくった\n"
	.string "{JPN}かせきふっかつそうちは すごいんだ.\p"
	.string "{JPN}でも ひとつ けってんが あって\n"
	.string "{JPN}じかんが かかるんだよ.\p"
	.string "{JPN}だから えーっと... ちょっと\n"
	.string "{JPN}そのへんを あるいてきたら?$"

RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife:
	.string "{JPN}おまたせ しました!\p"
	.string "{JPN}かせきの ポケモンが\n"
	.string "{JPN}いきかえりました!\p"
	.string "{JPN}かせきは こだいの ポケモン\n"
	.string "{JPN}{STR_VAR_2}でした!$"

RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher:
	.string "{JPN}{PLAYER}は けんきゅういんから\n"
	.string "{JPN}{STR_VAR_2}を うけとった.$"

@ Unused
RustboroCity_DevonCorp_2F_Text_TooManyPokemon:
	.string "{JPN}あらら  ポケモンを たくさん\n"
	.string "{JPN}もち すぎて いますね.\lこの この いりょは ありません.$"

RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature:
	.string "{JPN}ポケナビの あたらしい\n"
	.string "{JPN}きのうを かいはつしてるんだ...\p"
	.string "{JPN}でも うまくいってないんだよ.$"

RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext:
	.string "{JPN}さて  つぎは なにを\n"
	.string "{JPN}かいはつ しようかな?\p"
	.string "{JPN}わが しゃでは ひらめきを\n"
	.string "{JPN}げんじつに できるのです.\p"
	.string "{JPN}エンジニアには これいじょう\n"
	.string "{JPN}ない かんきょうですよ.$"

