data = {}

def ingest(input_data):
    parts = input_data.split(':')
    if len(parts) >= 2:
        project = parts[0]
        locations = parts[1:]
        if project not in data:
            data[project] = {}
        for location in locations:
            if location not in data[project]:
                data[project][location] = []

def appearance(project_location):
    total_occurrences = 0
    total_data_points = 0

    project, location = project_location.split(':')

    if project in data and location in data[project]:
        total_occurrences = len(data[project][location])
        
        for locations in data.values():
            if project in locations:
                total_data_points += len(locations[project])

        if total_data_points > 0:
            return total_occurrences / total_data_points
        else:
            return 0.0
    else:
        return 0.0

# Interactive loop
while True:
    user_input = input("Enter project-location-category (or 'exit' to quit): ")
    if user_input.lower() == 'exit':
        break
    ingest(user_input)
    project_location = ':'.join(user_input.split(':')[:2])
    score = appearance(project_location)
    print(f"Appearance score for '{project_location}': {score}")
