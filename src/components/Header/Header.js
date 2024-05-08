import {View, Text, StyleSheet} from 'react-native';
import React from 'react';
import Location from '../Location/Location';
import {TouchableOpacity} from 'react-native-gesture-handler';
import {Image} from 'react-native';
import Icon from 'react-native-vector-icons/FontAwesome';

const Header = () => {
  return (
    <>
      <View style={styles.headerContainer}>
        <View style={styles.headerItem}>
          <TouchableOpacity
            style={{
              elevation: 15,
            }}>
            <Image
              source={{
                uri: 'https://t4.ftcdn.net/jpg/03/64/21/11/360_F_364211147_1qgLVxv1Tcq0Ohz3FawUfrtONzz8nq3e.jpg',
              }}
              style={styles.profileImage}
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
              Fahad Mahamood
            </Text>
          </View>
        </View>
        <Icon size={24} color="white" name="bell" />
      </View>
      <Location />
    </>
  );
};

const styles = StyleSheet.create({
  headerContainer: {
    flexDirection: 'row',
    paddingHorizontal: 10,
    paddingVertical: 10,
    backgroundColor: '#355efc',
    justifyContent: 'space-between',
    alignItems: 'center',
    // position: 'fixed',
  },
  headerItem: {
    flexDirection: 'row',
    backgroundColor: '#355efc',
  },
  textName: {
    marginLeft: 10,
  },
  profileImage: {
    height: 40,
    width: 40,
    borderRadius: 50,
    evaluation: 15,
  },
});

export default Header;
