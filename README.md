# A Dynamic Reconfigure Node in C++

## Message format

```
string node_name
string param_name
string value
```

## Run

```
# Dynamic reconfigure server
rosrun params_reconfig server_node

# Dynamic reconfigure node
rosrun params_reconfig params_reconfig_node

# Node test
rosrun params_reconfig publisher_node

```

