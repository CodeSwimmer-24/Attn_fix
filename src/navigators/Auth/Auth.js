import {createStackNavigator} from '@react-navigation/stack';
import React from 'react';
import Home from '../../screen/Home/Home';
import WelcomeScreen from '../../screen/WelcomeScreen/WelcomeScreen';
import TabNavigation from '../TabNavigation/TabNavigation';

const Stack = createStackNavigator();

function Auth() {
  return (
    <Stack.Navigator
      screenOptions={{
        headerShown: false,
      }}>
      <Stack.Screen name="Login" component={WelcomeScreen} />
      <Stack.Screen name="TabNavigation" component={TabNavigation} />
    </Stack.Navigator>
  );
}

export default Auth;
