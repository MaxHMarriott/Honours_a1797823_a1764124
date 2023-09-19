import random

# Define the zones and intensities
zones = ["Zone 1", "Zone 2", "Zone 3", "Zone 4"]
intensities = ["High", "Medium", "Low"]

# Define the number of trials
num_trials = 5

# Generate and print 5 random trials
for trial in range(1, num_trials + 1):
    # Randomly select two distinct zones for this trial
    lit_zones = random.sample(zones, 2)

    # Randomly assign intensities to the lit zones
    intensity_a = random.choice(intensities)
    intensity_b = random.choice([intensity for intensity in intensities if intensity != intensity_a])

    # Create and print the trial description
    trial_description = f"Trial {trial}: {lit_zones[0]} ({intensity_a}), {lit_zones[1]} ({intensity_b})"
    print(trial_description)