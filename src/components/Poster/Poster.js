import {View, Image} from 'react-native';
import React from 'react';

const Poster = () => {
  return (
    <View
      style={{
        justifyContent: 'center',
        alignItems: 'center',
        marginTop: 20,
      }}>
      <Image
        source={{
          uri: 'https://d1csarkz8obe9u.cloudfront.net/posterpreviews/back-to-school-landscape-poster-design-template-1c0021a466a0734d4ed4fa93338983a7_screen.jpg?ts=1694178489',
        }}
        style={{
          height: 140,
          objectFit: 'cover',
          width: '90%',
          borderRadius: 15,
        }}
      />
    </View>
  );
};

export default Poster;
