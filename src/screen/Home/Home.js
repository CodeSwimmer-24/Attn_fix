import {View, Text, StyleSheet, Image} from 'react-native';
import React from 'react';
import {SafeAreaView} from 'react-native-safe-area-context';
import {TouchableOpacity} from 'react-native-gesture-handler';

const Home = () => {
  return (
    <SafeAreaView style={styles.container}>
      <View style={styles.headerContainer}>
        <TouchableOpacity
          style={{
            elevation: 15,
          }}>
          <Image
            source={{
              uri: 'https://t4.ftcdn.net/jpg/03/64/21/11/360_F_364211147_1qgLVxv1Tcq0Ohz3FawUfrtONzz8nq3e.jpg',
            }}
            style={{
              height: 45,
              width: 45,
              borderRadius: 50,
              evaluation: 15,
            }}
          />
        </TouchableOpacity>
        <View style={styles.textName}>
          <Text
            style={{
              fontSize: 13,
              color: 'white',
            }}>
            Hey 👋. Welcome 🎉
          </Text>
          <Text
            style={{
              fontSize: 18,
              fontWeight: '600',
              color: 'white',
            }}>
            Fahad Mhamood
          </Text>
        </View>
      </View>
    </SafeAreaView>
  );
};

const styles = StyleSheet.create({
  container: {
    backgroundColor: 'white',
    height: '100%',
  },
  headerContainer: {
    flexDirection: 'row',
    paddingHorizontal: 10,
    paddingVertical: 10,
    backgroundColor: '#355efc',
  },
  textName: {
    marginLeft: 10,
  },
});

export default Home;
