# Pwn challenges for PLUS newbies

## Create a new challenge
1. Add a directory with the challenge binary, the flag, and any other setup files.
2. Append the name of the challenge and the port number to `templates/challs_and_ports.txt`.

## Build
### For the first time
Add the name of the problem and the port that will be used to `templates/challs_and_ports.txt`.

```bash
# Generate files(xinetd and compose files) from the templates.
bash templates/scripts/instantiate-all.sh

# Build an essential docker image.
bash base/scripts/build.sh

# Build or rebuild using the compose file.
docker-compose build --no-cache
```

### Whenever you added a new challenge or modified an existing challenge
Add the name of the problem and the port that will be used to `templates/challs_and_ports.txt`.

```bash
# Re-generate files(xinetd and compose files) from the templates.
bash templates/scripts/instantiate-all.sh

# Build or rebuild using the compose file.
docker-compose build --no-cache <service_name>
```

## Deploy
```bash
docker-compose up -d
```
