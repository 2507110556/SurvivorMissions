# Reward Pool Spec (for Codex)

Goal:
- Replace hard-coded reward definitions in code with rewards loaded from `reward_pool.codex.json`.
- Two pools: Tier1, Tier2.
- Each pool has:
  - randomRewards: pick N items randomly (weighted)
  - fixedRewards: always granted (optional, can be empty)

## Data rules
- `minItems` / `maxItems`: inclusive range, choose a random count between them.
- Each entry:
  - `item`: DayZ classname (string)
  - `attachments`: list of item classnames to attach/spawn with the item
  - `quantity`: number
      - 0 means default quantity (do not force set)
      - >0 means set quantity/stack/ammo count when applicable
  - `weight`: number, used for weighted random selection (higher = more likely)
- If `fixedRewards` is empty, skip it.
- `crateName` is optional metadata (can be empty).

## Implementation notes (Codex should follow)
- Parse JSON once and cache.
- When generating rewards for a Tier:
  1) Add all fixedRewards
  2) Determine K in [minItems, maxItems]
  3) Do K weighted picks from randomRewards entries
     - Decide if repeats are allowed:
       - Default: allow repeats (simpler)
       - Optional: set `allowDuplicates=false` at pool level to disallow repeats
- Spawn/Grant items:
  - Create the base item
  - Apply quantity only if quantity > 0
  - Create attachments and attach if slots exist; otherwise spawn near player/container.

Files:
- reward_pool.codex.json  (actual data)
