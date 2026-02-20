class RewardPoolHelper
{
	private static ref array<string> m_Tier1Rewards;
	private static ref array<string> m_Tier2Rewards;

	private static void InitPools()
	{
		if (!m_Tier1Rewards)
		{
			m_Tier1Rewards = {
				"SalineBag", "Epinephrine", "BloodTestKit", "ExperementalAntidot", "DisinfectantSpray",
				"StartKitIV", "VitaminBottle", "PurificationTablets", "Pr_Syringe", "BandageDressing",
				"Morphine", "WoundInfectionAntidot", "CharcoalTablets", "DisinfectantAlcohol", "PainkillerTablets",
				"ChelatingTablets", "Nail", "BurlapStrip", "TireRepairKit", "EpoxyPutty",
				"ElectronicRepairKit", "AP_item_caroil", "LeatherSewingKit", "Pr_LeastherStrip", "SewingKit",
				"Whetstone", "KOD_plastir", "DuctTape", "AP_item_bluetape", "WeaponCleaningKit"
			};
		}

		if (!m_Tier2Rewards)
		{
			m_Tier2Rewards = {
				"BRDK_GameBoy", "Money_Ruble500", "Gold_Nugget", "BRDK_EFT_Chain2_Gold", "Coin",
				"Bitcoin", "BRDK_EFT_Chain_Gold", "BRDK_EFT_Chicken", "Money_Dollar20", "BRDK_EFT_Cat",
				"BRDK_EFT_Gpu", "Money_Dollar10", "pd_pearl", "BRDK_ID_Lab_CARD", "BRDK_ID_Dogtag_gold",
				"BRDK_ID_Medic_CARD", "BRDK_ID_NBC_CARD", "BRDK_ID_Rad_CARD", "BRDK_ID_Sec_CARD", "Goldbar_Dirty",
				"BRDK_ID_Soldier_CARD", "NBCGlovesBlack", "NBCHoodBlack", "NBCPantsBlack", "NBCBootsBlack",
				"NBCJacketBlack", "CombatKnife", "Mosin_Bayonet", "M9A1_Bayonet", "FB_Knife_homemade"
			};
		}
	}

	static void SpawnRandomTierRewards(ItemBase rewardContainer, out int selectedLoadout)
	{
		if (!rewardContainer)
		{
			selectedLoadout = 0;
			return;
		}

		InitPools();

		array<string> sourcePool;
		if (Math.RandomIntInclusive(0, 1) == 0)
		{
			sourcePool = m_Tier1Rewards;
			selectedLoadout = 1;
		}
		else
		{
			sourcePool = m_Tier2Rewards;
			selectedLoadout = 2;
		}

		int itemCount = Math.RandomIntInclusive(4, 8);
		for (int i = 0; i < itemCount; i++)
		{
			string rewardItem = sourcePool.GetRandomElement();
			if (rewardItem != string.Empty)
				rewardContainer.GetInventory().CreateInInventory(rewardItem);
		}
	}
}
