import React from 'react';
import {StyleSheet, Text} from 'react-native';
import {SafeAreaView} from 'react-native-safe-area-context';
import Header from '../../components/Header/Header';
import {ScrollView} from 'react-native-gesture-handler';
import HomeCategories from '../../components/HomeCategories/HomeCategories';
import Poster from '../../components/Poster/Poster';

const Home = () => {
  return (
    <SafeAreaView style={styles.container}>
      <Header />
      <ScrollView>
        <Poster />
        <HomeCategories />
      </ScrollView>
    </SafeAreaView>
  );
};

const styles = StyleSheet.create({
  container: {
    backgroundColor: 'white',
    height: '100%',
  },
});

export default Home;
