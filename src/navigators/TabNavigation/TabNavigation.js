import {View, Text} from 'react-native';
import React from 'react';
import {createBottomTabNavigator} from '@react-navigation/bottom-tabs';
import Home from '../../screen/Home/Home';
import Cart from '../../screen/Cart/Cart';
import Categories from '../../screen/Categories/Categories';
import Dashboard from '../../screen/Dashboard/Dashboard';
import Icon from 'react-native-vector-icons/FontAwesome';

const Tab = createBottomTabNavigator();
const TabNavigation = () => {
  return (
    <Tab.Navigator
      screenOptions={({route}) => ({
        headerShown: false,
        tabBarIcon: ({color, size, focused}) => {
          let iconName;

          if (route.name === 'Home') {
            iconName = focused ? 'home' : 'home-outline';
          } else if (route.name === 'Like') {
            iconName = focused ? 'home' : 'home';
          } else if (route.name === 'Categories') {
            iconName = focused ? 'home' : 'home';
          } else if (route.name === 'Dashboard') {
            iconName = focused ? 'home' : 'home';
          }
          return <Icon name={iconName} size={22} color="black" />;
        },
      })}>
      <Tab.Screen name="Home" component={Home} />
      <Tab.Screen name="Like" component={Cart} />
      <Tab.Screen name="Categories" component={Categories} />
      <Tab.Screen name="Dashboard" component={Dashboard} />
    </Tab.Navigator>
  );
};

export default TabNavigation;
