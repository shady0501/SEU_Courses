#### 目录结构

│ 
├─db 存储与数据库相关的文件
│
├─doc 项目的文档目录，包括用户手册、设计文档、API 文档、架构图等。
│
├─es 与 Elasticsearch 相关的配置，包含搜索引擎的配置文件、数据处理逻辑等。
│
├─front-end 前端代码目录，通常包含 HTML、CSS、JavaScript 文件，以及前端框架（如 Vue.js、React 等）的相关代码。
│
├─mall4cloud-api
│  │  pom.xml
│  │
│  ├─mall4cloud-api-auth
│  │  │  pom.xml
│  │  │
│  │  └─src
│  │      └─main
│  │          └─java
│  │              └─com
│  │                  └─mall4j
│  │                      └─cloud
│  │                          └─api
│  │                              └─auth
│  │                                  ├─bo
│  │                                  │      UserInfoInTokenBO.java
│  │                                  │
│  │                                  ├─constant
│  │                                  │      SysTypeEnum.java
│  │                                  │
│  │                                  ├─dto
│  │                                  │      AuthAccountDTO.java
│  │                                  │
│  │                                  ├─feign
│  │                                  │      AccountFeignClient.java
│  │                                  │      TokenFeignClient.java
│  │                                  │
│  │                                  └─vo
│  │                                          AuthAccountVO.java
│  │                                          TokenInfoVO.java
│  │
│  ├─mall4cloud-api-biz
│  │      pom.xml
│  │
│  ├─mall4cloud-api-leaf
│  │  │  pom.xml
│  │  │
│  │  └─src
│  │      └─main
│  │          └─java
│  │              └─com
│  │                  └─mall4j
│  │                      └─cloud
│  │                          └─api
│  │                              └─leaf
│  │                                  └─feign
│  │                                          SegmentFeignClient.java
│  │
│  ├─mall4cloud-api-multishop
│  │  │  pom.xml
│  │  │
│  │  └─src
│  │      └─main
│  │          └─java
│  │              └─com
│  │                  └─mall4j
│  │                      └─cloud
│  │                          └─api
│  │                              └─multishop
│  │                                  ├─bo
│  │                                  │      EsShopDetailBO.java
│  │                                  │
│  │                                  ├─feign
│  │                                  │      IndexImgFeignClient.java
│  │                                  │      ShopDetailFeignClient.java
│  │                                  │
│  │                                  └─vo
│  │                                          ShopDetailVO.java
│  │
│  ├─mall4cloud-api-order
│  │  │  pom.xml
│  │  │
│  │  └─src
│  │      └─main
│  │          └─java
│  │              └─com
│  │                  └─mall4j
│  │                      └─cloud
│  │                          └─api
│  │                              └─order
│  │                                  ├─bo
│  │                                  │      EsOrderBO.java
│  │                                  │      EsOrderItemBO.java
│  │                                  │      OrderSimpleAmountInfoBO.java
│  │                                  │      OrderStatusBO.java
│  │                                  │
│  │                                  ├─constant
│  │                                  │      DeliveryType.java
│  │                                  │      OrderStatus.java
│  │                                  │
│  │                                  ├─dto
│  │                                  │      DeliveryOrderDTO.java
│  │                                  │      DeliveryOrderItemDTO.java
│  │                                  │
│  │                                  ├─feign
│  │                                  │      OrderFeignClient.java
│  │                                  │
│  │                                  └─vo
│  │                                          OrderAmountVO.java
│  │
│  ├─mall4cloud-api-platform
│  │  │  pom.xml
│  │  │
│  │  └─src
│  │      └─main
│  │          └─java
│  │              └─com
│  │                  └─mall4j
│  │                      └─cloud
│  │                          └─api
│  │                              └─platform
│  │                                  └─feign
│  │                                          ConfigFeignClient.java
│  │
│  ├─mall4cloud-api-product
│  │  │  pom.xml
│  │  │
│  │  └─src
│  │      └─main
│  │          └─java
│  │              └─com
│  │                  └─mall4j
│  │                      └─cloud
│  │                          └─api
│  │                              └─product
│  │                                  ├─bo
│  │                                  │      EsAttrBO.java
│  │                                  │      EsProductBO.java
│  │                                  │
│  │                                  ├─constant
│  │                                  │      CategoryLevel.java
│  │                                  │
│  │                                  ├─dto
│  │                                  │      ShopCartItemDTO.java
│  │                                  │      SkuStockLockDTO.java
│  │                                  │      SpuUpdateDTO.java
│  │                                  │
│  │                                  ├─feign
│  │                                  │      CategoryFeignClient.java
│  │                                  │      ProductFeignClient.java
│  │                                  │      ShopCartFeignClient.java
│  │                                  │      SkuFeignClient.java
│  │                                  │      SkuStockLockFeignClient.java
│  │                                  │      SpuFeignClient.java
│  │                                  │
│  │                                  ├─manager
│  │                                  │      ShopCartAdapter.java
│  │                                  │
│  │                                  └─vo
│  │                                          AttrCategoryVO.java
│  │                                          AttrValueVO.java
│  │                                          AttrVO.java
│  │                                          BrandVO.java
│  │                                          CategoryVO.java
│  │                                          SkuVO.java
│  │                                          SpuAndSkuVO.java
│  │                                          SpuAttrValueVO.java
│  │                                          SpuSkuAttrValueVO.java
│  │                                          SpuVO.java
│  │
│  ├─mall4cloud-api-rbac
│  │  │  pom.xml
│  │  │
│  │  └─src
│  │      └─main
│  │          └─java
│  │              └─com
│  │                  └─mall4j
│  │                      └─cloud
│  │                          └─api
│  │                              └─rbac
│  │                                  ├─bo
│  │                                  │      UriPermissionBO.java
│  │                                  │
│  │                                  ├─constant
│  │                                  │      HttpMethodEnum.java
│  │                                  │
│  │                                  ├─dto
│  │                                  │      CheckPermissionDTO.java
│  │                                  │      ClearUserPermissionsCacheDTO.java
│  │                                  │      UserRoleDTO.java
│  │                                  │
│  │                                  └─feign
│  │                                          PermissionFeignClient.java
│  │                                          UserRoleFeignClient.java
│  │
│  ├─mall4cloud-api-search
│  │  │  pom.xml
│  │  │
│  │  └─src
│  │      └─main
│  │          └─java
│  │              └─com
│  │                  └─mall4j
│  │                      └─cloud
│  │                          └─api
│  │                              ├─dto
│  │                              │      EsPageDTO.java
│  │                              │      ProductSearchDTO.java
│  │                              │
│  │                              ├─feign
│  │                              │      SearchOrderFeignClient.java
│  │                              │      SearchSpuFeignClient.java
│  │                              │
│  │                              └─vo
│  │                                  │  EsPageVO.java
│  │                                  │
│  │                                  └─search
│  │                                          AttrSearchVO.java
│  │                                          AttrValueSearchVO.java
│  │                                          BrandSearchVO.java
│  │                                          CategorySearchVO.java
│  │                                          EsOrderItemVO.java
│  │                                          EsOrderVO.java
│  │                                          ProductSearchVO.java
│  │                                          ShopInfoSearchVO.java
│  │                                          SpuSearchVO.java
│  │
│  └─mall4cloud-api-user
│      │  pom.xml
│      │
│      └─src
│          └─main
│              └─java
│                  └─com
│                      └─mall4j
│                          └─cloud
│                              └─api
│                                  └─user
│                                      ├─feign
│                                      │      UserAddrFeignClient.java
│                                      │      UserFeignClient.java
│                                      │
│                                      └─vo
│                                              AreaVO.java
│                                              UserApiVO.java
│
├─mall4cloud-auth
│  │  pom.xml
│  │
│  └─src
│      └─main
│          ├─java
│          │  └─com
│          │      └─mall4j
│          │          └─cloud
│          │              └─auth
│          │                  │  AuthApplication.java
│          │                  │
│          │                  ├─adapter
│          │                  │      CaptchaCacheServiceRedisImpl.java
│          │                  │
│          │                  ├─config
│          │                  │      CaptchaConfig.java
│          │                  │
│          │                  ├─constant
│          │                  │      AuthAccountStatusEnum.java
│          │                  │
│          │                  ├─controller
│          │                  │      CaptchaController.java
│          │                  │      LoginController.java
│          │                  │      PasswordController.java
│          │                  │      TokenController.java
│          │                  │
│          │                  ├─dto
│          │                  │      AuthenticationDTO.java
│          │                  │      CaptchaAuthenticationDTO.java
│          │                  │      RefreshTokenDTO.java
│          │                  │      UpdatePasswordDTO.java
│          │                  │
│          │                  ├─feign
│          │                  │      AccountFeignController.java
│          │                  │      TokenFeignController.java
│          │                  │
│          │                  ├─manager
│          │                  │      TokenStore.java
│          │                  │
│          │                  ├─mapper
│          │                  │      AuthAccountMapper.java
│          │                  │
│          │                  ├─model
│          │                  │      AuthAccount.java
│          │                  │
│          │                  └─service
│          │                      │  AuthAccountService.java
│          │                      │
│          │                      └─impl
│          │                              AuthAccountServiceImpl.java
│          │
│          └─resources
│              │  bootstrap.yml
│              │
│              ├─captcha
│              │  ├─original
│              │  │      1.png
│              │  │      2.png
│              │  │      3.png
│              │  │      4.png
│              │  │      5.png
│              │  │      6.png
│              │  │
│              │  └─slidingBlock
│              │          1.png
│              │          2.png
│              │          3.png
│              │          4.png
│              │
│              ├─mapper
│              │      AuthAccountMapper.xml
│              │
│              └─META-INF
│                  └─services
│                          com.anji.captcha.service.CaptchaCacheService
│
├─mall4cloud-biz
│  │  pom.xml
│  │
│  └─src
│      └─main
│          ├─java
│          │  └─com
│          │      └─mall4j
│          │          └─cloud
│          │              └─biz
│          │                  │  BizServerApplication.java
│          │                  │
│          │                  ├─config
│          │                  │      MinioTemplate.java
│          │                  │      OssConfig.java
│          │                  │
│          │                  ├─constant
│          │                  │      OssType.java
│          │                  │
│          │                  ├─controller
│          │                  │  │  OssController.java
│          │                  │  │
│          │                  │  └─multishop
│          │                  │          AttachFileController.java
│          │                  │          AttachFileGroupController.java
│          │                  │
│          │                  ├─dto
│          │                  │      AttachFileDTO.java
│          │                  │      AttachFileGroupDTO.java
│          │                  │
│          │                  ├─mapper
│          │                  │      AttachFileGroupMapper.java
│          │                  │      AttachFileMapper.java
│          │                  │
│          │                  ├─model
│          │                  │      AttachFile.java
│          │                  │      AttachFileGroup.java
│          │                  │
│          │                  ├─service
│          │                  │  │  AttachFileGroupService.java
│          │                  │  │  AttachFileService.java
│          │                  │  │
│          │                  │  └─impl
│          │                  │          AttachFileGroupServiceImpl.java
│          │                  │          AttachFileServiceImpl.java
│          │                  │
│          │                  └─vo
│          │                          AttachFileGroupVO.java
│          │                          AttachFileVO.java
│          │                          OssVO.java
│          │
│          └─resources
│              │  bootstrap.yml
│              │
│              └─mapper
│                      AttachFileGroupMapper.xml
│                      AttachFileMapper.xml
│
├─mall4cloud-common
│  │  pom.xml
│  │
│  ├─mall4cloud-common-cache
│  │  │  pom.xml
│  │  │  README.md
│  │  │
│  │  └─src
│  │      └─main
│  │          └─java
│  │              └─com
│  │                  └─mall4j
│  │                      └─cloud
│  │                          └─common
│  │                              └─cache
│  │                                  ├─adapter
│  │                                  │      CacheTtlAdapter.java
│  │                                  │
│  │                                  ├─bo
│  │                                  │      CacheNameWithTtlBO.java
│  │                                  │
│  │                                  ├─config
│  │                                  │      RedisCacheConfig.java
│  │                                  │      RedisLockConfiguration.java
│  │                                  │
│  │                                  ├─constant
│  │                                  │      BizCacheNames.java
│  │                                  │      CacheNames.java
│  │                                  │      ConfigCacheNames.java
│  │                                  │      MultishopCacheNames.java
│  │                                  │      OauthCacheNames.java
│  │                                  │      OrderCacheNames.java
│  │                                  │      PlatformCacheNames.java
│  │                                  │      ProductCacheNames.java
│  │                                  │      RbacCacheNames.java
│  │                                  │      UserCacheNames.java
│  │                                  │
│  │                                  └─util
│  │                                          CacheManagerUtil.java
│  │                                          RedisUtil.java
│  │
│  ├─mall4cloud-common-core
│  │  │  pom.xml
│  │  │
│  │  ├─lib
│  │  │      canal-glue-core.jar
│  │  │
│  │  └─src
│  │      └─main
│  │          └─java
│  │              └─com
│  │                  └─mall4j
│  │                      └─cloud
│  │                          └─common
│  │                              ├─config
│  │                              │      AopConfig.java
│  │                              │      RestTemplateConfig.java
│  │                              │
│  │                              ├─constant
│  │                              │      Auth.java
│  │                              │      Constant.java
│  │                              │      StatusEnum.java
│  │                              │      UserAdminType.java
│  │                              │
│  │                              ├─dto
│  │                              │      BaseDTO.java
│  │                              │      OrderSearchDTO.java
│  │                              │
│  │                              ├─exception
│  │                              │      Mall4cloudException.java
│  │                              │
│  │                              ├─feign
│  │                              │      FeignBasicAuthRequestInterceptor.java
│  │                              │      FeignHttpClientConfig.java
│  │                              │      FeignInsideAuthConfig.java
│  │                              │
│  │                              ├─handler
│  │                              │      DefaultExceptionHandlerConfig.java
│  │                              │      HttpHandler.java
│  │                              │
│  │                              ├─model
│  │                              │      BaseModel.java
│  │                              │
│  │                              ├─response
│  │                              │      ResponseEnum.java
│  │                              │      ServerResponseEntity.java
│  │                              │
│  │                              ├─serializer
│  │                              │      ImgJsonSerializer.java
│  │                              │
│  │                              ├─util
│  │                              │      BeanUtil.java
│  │                              │      BooleanUtil.java
│  │                              │      IpHelper.java
│  │                              │      Json.java
│  │                              │      PrincipalUtil.java
│  │                              │      SpringContextUtils.java
│  │                              │
│  │                              └─vo
│  │                                      BaseVO.java
│  │
│  ├─mall4cloud-common-database
│  │  │  pom.xml
│  │  │
│  │  └─src
│  │      └─main
│  │          └─java
│  │              └─com
│  │                  └─mall4j
│  │                      └─cloud
│  │                          └─common
│  │                              └─database
│  │                                  ├─annotations
│  │                                  │      DistributedId.java
│  │                                  │
│  │                                  ├─config
│  │                                  │      MybatisConfig.java
│  │                                  │      SeataRequestInterceptor.java
│  │                                  │
│  │                                  ├─dto
│  │                                  │      PageDTO.java
│  │                                  │
│  │                                  ├─interceptor
│  │                                  │      GeneratedKeyInterceptor.java
│  │                                  │
│  │                                  ├─util
│  │                                  │      PageAdapter.java
│  │                                  │      PageUtil.java
│  │                                  │
│  │                                  └─vo
│  │                                          PageVO.java
│  │
│  ├─mall4cloud-common-order
│  │  │  pom.xml
│  │  │
│  │  └─src
│  │      └─main
│  │          └─java
│  │              └─com
│  │                  └─mall4j
│  │                      └─cloud
│  │                          └─common
│  │                              └─order
│  │                                  ├─bo
│  │                                  │      PayNotifyBO.java
│  │                                  │
│  │                                  ├─constant
│  │                                  │      OrderCloseType.java
│  │                                  │
│  │                                  └─vo
│  │                                          ShopCartItemVO.java
│  │                                          ShopCartOrderMergerVO.java
│  │                                          ShopCartOrderVO.java
│  │                                          ShopCartVO.java
│  │                                          ShopCartWithAmountVO.java
│  │                                          UserAddrVO.java
│  │
│  ├─mall4cloud-common-rocketmq
│  │  │  pom.xml
│  │  │
│  │  └─src
│  │      └─main
│  │          └─java
│  │              └─com
│  │                  └─mall4j
│  │                      └─cloud
│  │                          └─common
│  │                              └─rocketmq
│  │                                  └─config
│  │                                          RocketMqAdapter.java
│  │                                          RocketMqConstant.java
│  │
│  └─mall4cloud-common-security
│      │  pom.xml
│      │
│      └─src
│          └─main
│              └─java
│                  └─com
│                      └─mall4j
│                          └─cloud
│                              └─common
│                                  └─security
│                                      │  AuthUserContext.java
│                                      │
│                                      ├─adapter
│                                      │      AuthConfigAdapter.java
│                                      │      DefaultAuthConfigAdapter.java
│                                      │
│                                      ├─bo
│                                      │      AuthAccountInVerifyBO.java
│                                      │      TokenInfoBO.java
│                                      │
│                                      ├─config
│                                      │      AuthConfig.java
│                                      │      PasswordConfig.java
│                                      │
│                                      ├─constant
│                                      │      InputUserNameEnum.java
│                                      │
│                                      └─filter
│                                              AuthFilter.java
│
├─mall4cloud-gateway
│  │  pom.xml
│  │
│  └─src
│      └─main
│          ├─java
│          │  └─com
│          │      └─mall4j
│          │          └─cloud
│          │              └─gateway
│          │                      GatewayApplication.java
│          │
│          └─resources
│                  bootstrap.yml
│
├─mall4cloud-leaf
│  │  pom.xml
│  │
│  └─src
│      └─main
│          ├─java
│          │  └─com
│          │      └─mall4j
│          │          └─cloud
│          │              └─leaf
│          │                  │  IDGen.java
│          │                  │  LeafServerApplication.java
│          │                  │
│          │                  ├─common
│          │                  │      Result.java
│          │                  │      Status.java
│          │                  │      ZeroIDGen.java
│          │                  │
│          │                  ├─exception
│          │                  │      InitException.java
│          │                  │      LeafServerException.java
│          │                  │      NoKeyException.java
│          │                  │
│          │                  ├─feign
│          │                  │      SegmentFeignController.java
│          │                  │
│          │                  ├─segment
│          │                  │  │  SegmentIDGenImpl.java
│          │                  │  │
│          │                  │  ├─dao
│          │                  │  │  │  IDAllocDao.java
│          │                  │  │  │  IDAllocMapper.java
│          │                  │  │  │
│          │                  │  │  └─impl
│          │                  │  │          IDAllocDaoImpl.java
│          │                  │  │
│          │                  │  └─model
│          │                  │          LeafAlloc.java
│          │                  │          Segment.java
│          │                  │          SegmentBuffer.java
│          │                  │
│          │                  └─service
│          │                          SegmentService.java
│          │
│          └─resources
│                  bootstrap.yml
│
├─mall4cloud-multishop
│  │  pom.xml
│  │
│  └─src
│      └─main
│          ├─java
│          │  └─com
│          │      └─mall4j
│          │          └─cloud
│          │              └─multishop
│          │                  │  MultishopApplication.java
│          │                  │
│          │                  ├─constant
│          │                  │      ShopStatus.java
│          │                  │      ShopType.java
│          │                  │
│          │                  ├─controller
│          │                  │  │  ShopUserAccountController.java
│          │                  │  │
│          │                  │  ├─admin
│          │                  │  │      HotSearchController.java
│          │                  │  │      IndexImgController.java
│          │                  │  │
│          │                  │  ├─app
│          │                  │  │      HotSearchController.java
│          │                  │  │      IndexImgController.java
│          │                  │  │      MyShopDetailController.java
│          │                  │  │      ShopDetailController.java
│          │                  │  │
│          │                  │  ├─multishop
│          │                  │  │      ShopDetailController.java
│          │                  │  │      ShopUserController.java
│          │                  │  │
│          │                  │  └─platform
│          │                  │          ShopDetailController.java
│          │                  │
│          │                  ├─dto
│          │                  │      ChangeAccountDTO.java
│          │                  │      HotSearchDTO.java
│          │                  │      IndexImgDTO.java
│          │                  │      ShopDetailDTO.java
│          │                  │      ShopUserDTO.java
│          │                  │      UpdateShopPasswordDTO.java
│          │                  │      UsernameAndPasswordDTO.java
│          │                  │
│          │                  ├─feign
│          │                  │      IndexImgFeignController.java
│          │                  │      ShopDetailFeignController.java
│          │                  │
│          │                  ├─mapper
│          │                  │      HotSearchMapper.java
│          │                  │      IndexImgMapper.java
│          │                  │      ShopDetailMapper.java
│          │                  │      ShopUserMapper.java
│          │                  │
│          │                  ├─model
│          │                  │      HotSearch.java
│          │                  │      IndexImg.java
│          │                  │      ShopDetail.java
│          │                  │      ShopUser.java
│          │                  │
│          │                  ├─service
│          │                  │  │  HotSearchService.java
│          │                  │  │  IndexImgService.java
│          │                  │  │  ShopDetailService.java
│          │                  │  │  ShopUserAccountService.java
│          │                  │  │  ShopUserService.java
│          │                  │  │
│          │                  │  └─impl
│          │                  │          HotSearchServiceImpl.java
│          │                  │          IndexImgServiceImpl.java
│          │                  │          ShopDetailServiceImpl.java
│          │                  │          ShopUserAccountServiceImpl.java
│          │                  │          ShopUserServiceImpl.java
│          │                  │
│          │                  └─vo
│          │                          HotSearchVO.java
│          │                          IndexImgVO.java
│          │                          ShopDetailAppVO.java
│          │                          ShopHeadInfoVO.java
│          │                          ShopUserSimpleVO.java
│          │                          ShopUserVO.java
│          │
│          └─resources
│              │  bootstrap.yml
│              │
│              └─mapper
│                      HotSearchMapper.xml
│                      IndexImgMapper.xml
│                      ShopDetailMapper.xml
│                      ShopUserMapper.xml
│
├─mall4cloud-order
│  │  pom.xml
│  │
│  └─src
│      └─main
│          ├─java
│          │  └─com
│          │      └─mall4j
│          │          └─cloud
│          │              └─order
│          │                  │  OrderApplication.java
│          │                  │
│          │                  ├─bo
│          │                  │      SubmitOrderPayAmountInfoBO.java
│          │                  │
│          │                  ├─config
│          │                  │      OrderCacheTtlAdapter.java
│          │                  │      RocketMqConfig.java
│          │                  │
│          │                  ├─controller
│          │                  │  ├─app
│          │                  │  │      MyOrderController.java
│          │                  │  │      OrderController.java
│          │                  │  │
│          │                  │  └─multishop
│          │                  │          OrderController.java
│          │                  │
│          │                  ├─dto
│          │                  │  ├─app
│          │                  │  │      OrderDTO.java
│          │                  │  │
│          │                  │  └─multishop
│          │                  │          OrderAdminDTO.java
│          │                  │          OrderItemDTO.java
│          │                  │
│          │                  ├─feign
│          │                  │      OrderFeignController.java
│          │                  │
│          │                  ├─listener
│          │                  │      OrderCancelConsumer.java
│          │                  │      OrderNotifyConsumer.java
│          │                  │
│          │                  ├─mapper
│          │                  │      OrderAddrMapper.java
│          │                  │      OrderItemMapper.java
│          │                  │      OrderMapper.java
│          │                  │      OrderPayInfoMapper.java
│          │                  │
│          │                  ├─model
│          │                  │      Order.java
│          │                  │      OrderAddr.java
│          │                  │      OrderItem.java
│          │                  │      OrderPayInfo.java
│          │                  │
│          │                  ├─service
│          │                  │  │  OrderAddrService.java
│          │                  │  │  OrderItemService.java
│          │                  │  │  OrderPayInfoService.java
│          │                  │  │  OrderService.java
│          │                  │  │
│          │                  │  └─impl
│          │                  │          OrderAddrServiceImpl.java
│          │                  │          OrderItemServiceImpl.java
│          │                  │          OrderPayInfoServiceImpl.java
│          │                  │          OrderServiceImpl.java
│          │                  │
│          │                  └─vo
│          │                          MyOrderItemVO.java
│          │                          MyOrderVO.java
│          │                          OrderAddrVO.java
│          │                          OrderCountVO.java
│          │                          OrderItemVO.java
│          │                          OrderPayInfoVO.java
│          │                          OrderShopVO.java
│          │                          OrderVO.java
│          │                          SubmitOrderPayInfoVO.java
│          │
│          └─resources
│              │  bootstrap.yml
│              │
│              └─mapper
│                      OrderAddrMapper.xml
│                      OrderItemMapper.xml
│                      OrderMapper.xml
│                      OrderPayInfoMapper.xml
│
├─mall4cloud-payment
│  │  pom.xml
│  │
│  └─src
│      └─main
│          ├─java
│          │  └─com
│          │      └─mall4j
│          │          └─cloud
│          │              └─payment
│          │                  │  PaymentApplication.java
│          │                  │
│          │                  ├─bo
│          │                  │      PayInfoBO.java
│          │                  │      PayInfoResultBO.java
│          │                  │
│          │                  ├─config
│          │                  │      RocketMqConfig.java
│          │                  │
│          │                  ├─constant
│          │                  │      BackType.java
│          │                  │      PayStatus.java
│          │                  │
│          │                  ├─controller
│          │                  │      PayController.java
│          │                  │      PayNoticeController.java
│          │                  │
│          │                  ├─dto
│          │                  │      PayInfoDTO.java
│          │                  │
│          │                  ├─mapper
│          │                  │      PayInfoMapper.java
│          │                  │
│          │                  ├─model
│          │                  │      PayInfo.java
│          │                  │
│          │                  └─service
│          │                      │  PayInfoService.java
│          │                      │
│          │                      └─impl
│          │                              PayInfoServiceImpl.java
│          │
│          └─resources
│              │  bootstrap.yml
│              │
│              └─mapper
│                      PayInfoMapper.xml
│
├─mall4cloud-platform
│  │  pom.xml
│  │
│  └─src
│      └─main
│          ├─java
│          │  └─com
│          │      └─mall4j
│          │          └─cloud
│          │              └─platform
│          │                  │  PlatformApplication.java
│          │                  │
│          │                  ├─controller
│          │                  │      SysConfigController.java
│          │                  │      SysUserAccountController.java
│          │                  │      SysUserController.java
│          │                  │
│          │                  ├─dto
│          │                  │      ChangeAccountDTO.java
│          │                  │      SysConfigDTO.java
│          │                  │      SysUserDTO.java
│          │                  │
│          │                  ├─feign
│          │                  │      ConfigFeignController.java
│          │                  │
│          │                  ├─mapper
│          │                  │      SysConfigMapper.java
│          │                  │      SysUserMapper.java
│          │                  │
│          │                  ├─model
│          │                  │      SysConfig.java
│          │                  │      SysUser.java
│          │                  │
│          │                  ├─service
│          │                  │  │  SysConfigService.java
│          │                  │  │  SysUserAccountService.java
│          │                  │  │  SysUserService.java
│          │                  │  │
│          │                  │  └─impl
│          │                  │          SysConfigServiceImpl.java
│          │                  │          SysUserAccountServiceImpl.java
│          │                  │          SysUserServiceImpl.java
│          │                  │
│          │                  └─vo
│          │                          SysConfigVO.java
│          │                          SysUserSimpleVO.java
│          │                          SysUserVO.java
│          │
│          └─resources
│              │  bootstrap.yml
│              │
│              └─mapper
│                      SysConfigMapper.xml
│                      SysUserMapper.xml
│
├─mall4cloud-product
│  │  pom.xml
│  │
│  └─src
│      └─main
│          ├─java
│          │  └─com
│          │      └─mall4j
│          │          └─cloud
│          │              └─product
│          │                  │  ProductApplication.java
│          │                  │
│          │                  ├─bo
│          │                  │      SkuWithStockBO.java
│          │                  │
│          │                  ├─config
│          │                  │      RocketMqConfig.java
│          │                  │
│          │                  ├─constant
│          │                  │      AttrType.java
│          │                  │      SearchType.java
│          │                  │
│          │                  ├─controller
│          │                  │  ├─admin
│          │                  │  │      AttrController.java
│          │                  │  │      BrandController.java
│          │                  │  │      CategoryController.java
│          │                  │  │      SkuStockLockController.java
│          │                  │  │      SpuController.java
│          │                  │  │
│          │                  │  ├─app
│          │                  │  │      AttrController.java
│          │                  │  │      BrandController.java
│          │                  │  │      CategoryController.java
│          │                  │  │      ShopCartController.java
│          │                  │  │      SkuStockLockController.java
│          │                  │  │      SpuController.java
│          │                  │  │
│          │                  │  └─platform
│          │                  │          BrandController.java
│          │                  │
│          │                  ├─dto
│          │                  │  │  AttrCategoryDTO.java
│          │                  │  │  AttrDTO.java
│          │                  │  │  AttrValueDTO.java
│          │                  │  │  BrandDTO.java
│          │                  │  │  CategoryBrandDTO.java
│          │                  │  │  CategoryDTO.java
│          │                  │  │  SkuDTO.java
│          │                  │  │  SkuStockDTO.java
│          │                  │  │  SkuStockLockDTO.java
│          │                  │  │  SpuAttrValueDTO.java
│          │                  │  │  SpuDetailDTO.java
│          │                  │  │  SpuDTO.java
│          │                  │  │  SpuExtensionDTO.java
│          │                  │  │  SpuPageSearchDTO.java
│          │                  │  │  SpuSkuAttrValueDTO.java
│          │                  │  │
│          │                  │  └─shopcart
│          │                  │          ChangeShopCartItemDTO.java
│          │                  │          CheckShopCartItemDTO.java
│          │                  │
│          │                  ├─feign
│          │                  │      CategoryFeignController.java
│          │                  │      ProductFeignController.java
│          │                  │      ShopCartFeignController.java
│          │                  │      SkuFeignController.java
│          │                  │      SkuStockLockFeignController.java
│          │                  │      SpuFeignController.java
│          │                  │
│          │                  ├─listener
│          │                  │      OrderNotifyStockConsumer.java
│          │                  │      StockUnlockConsumer.java
│          │                  │
│          │                  ├─mapper
│          │                  │      AttrCategoryMapper.java
│          │                  │      AttrMapper.java
│          │                  │      AttrValueMapper.java
│          │                  │      BrandMapper.java
│          │                  │      CategoryBrandMapper.java
│          │                  │      CategoryMapper.java
│          │                  │      ShopCartItemMapper.java
│          │                  │      SkuMapper.java
│          │                  │      SkuStockLockMapper.java
│          │                  │      SkuStockMapper.java
│          │                  │      SpuAttrValueMapper.java
│          │                  │      SpuDetailMapper.java
│          │                  │      SpuExtensionMapper.java
│          │                  │      SpuMapper.java
│          │                  │      SpuSkuAttrValueMapper.java
│          │                  │
│          │                  ├─model
│          │                  │      Attr.java
│          │                  │      AttrCategory.java
│          │                  │      AttrValue.java
│          │                  │      Brand.java
│          │                  │      Category.java
│          │                  │      CategoryBrand.java
│          │                  │      ShopCartItem.java
│          │                  │      Sku.java
│          │                  │      SkuStock.java
│          │                  │      SkuStockLock.java
│          │                  │      Spu.java
│          │                  │      SpuAttrValue.java
│          │                  │      SpuDetail.java
│          │                  │      SpuExtension.java
│          │                  │      SpuSkuAttrValue.java
│          │                  │
│          │                  ├─service
│          │                  │  │  AttrCategoryService.java
│          │                  │  │  AttrService.java
│          │                  │  │  AttrValueService.java
│          │                  │  │  BrandService.java
│          │                  │  │  CategoryAndSpuService.java
│          │                  │  │  CategoryBrandService.java
│          │                  │  │  CategoryService.java
│          │                  │  │  ShopCartService.java
│          │                  │  │  SkuService.java
│          │                  │  │  SkuStockLockService.java
│          │                  │  │  SkuStockService.java
│          │                  │  │  SpuAttrValueService.java
│          │                  │  │  SpuDetailService.java
│          │                  │  │  SpuExtensionService.java
│          │                  │  │  SpuService.java
│          │                  │  │  SpuSkuAttrValueService.java
│          │                  │  │
│          │                  │  └─impl
│          │                  │          AttrCategoryServiceImpl.java
│          │                  │          AttrServiceImpl.java
│          │                  │          AttrValueServiceImpl.java
│          │                  │          BrandServiceImpl.java
│          │                  │          CategoryAndSpuServiceImpl.java
│          │                  │          CategoryBrandServiceImpl.java
│          │                  │          CategoryServiceImpl.java
│          │                  │          ShopCartServiceImpl.java
│          │                  │          SkuServiceImpl.java
│          │                  │          SkuStockLockServiceImpl.java
│          │                  │          SkuStockServiceImpl.java
│          │                  │          SpuAttrValueServiceImpl.java
│          │                  │          SpuDetailServiceImpl.java
│          │                  │          SpuExtensionServiceImpl.java
│          │                  │          SpuServiceImpl.java
│          │                  │          SpuSkuAttrValueServiceImpl.java
│          │                  │
│          │                  └─vo
│          │                      │  CategoryBrandVO.java
│          │                      │  ShopCartAmountVO.java
│          │                      │  SkuStockLockVO.java
│          │                      │  SkuStockVO.java
│          │                      │  SpuDetailVO.java
│          │                      │  SpuExtensionVO.java
│          │                      │
│          │                      └─app
│          │                              SkuAppVO.java
│          │                              SpuAppVO.java
│          │
│          └─resources
│              │  bootstrap.yml
│              │
│              └─mapper
│                      AttrCategoryMapper.xml
│                      AttrMapper.xml
│                      AttrValueMapper.xml
│                      BrandMapper.xml
│                      CategoryBrandMapper.xml
│                      CategoryMapper.xml
│                      ShopCartItemMapper.xml
│                      SkuMapper.xml
│                      SkuStockLockMapper.xml
│                      SkuStockMapper.xml
│                      SpuAttrValueMapper.xml
│                      SpuDetailMapper.xml
│                      SpuExtensionMapper.xml
│                      SpuMapper.xml
│                      SpuSkuAttrValueMapper.xml
│
├─mall4cloud-rbac
│  │  pom.xml
│  │
│  └─src
│      └─main
│          ├─java
│          │  └─com
│          │      └─mall4j
│          │          └─cloud
│          │              └─rbac
│          │                  │  RbacApplication.java
│          │                  │
│          │                  ├─controller
│          │                  │      MenuController.java
│          │                  │      MenuPermissionController.java
│          │                  │      RoleController.java
│          │                  │
│          │                  ├─dto
│          │                  │      MenuDTO.java
│          │                  │      MenuPermissionDTO.java
│          │                  │      MenuWithPermissionIdDTO.java
│          │                  │      RoleDTO.java
│          │                  │
│          │                  ├─feign
│          │                  │      PermissionFeignController.java
│          │                  │
│          │                  ├─mapper
│          │                  │      MenuMapper.java
│          │                  │      MenuPermissionMapper.java
│          │                  │      RoleMapper.java
│          │                  │      RoleMenuMapper.java
│          │                  │      UserRoleMapper.java
│          │                  │
│          │                  ├─model
│          │                  │      Menu.java
│          │                  │      MenuPermission.java
│          │                  │      Role.java
│          │                  │      RoleMenu.java
│          │                  │      UserRole.java
│          │                  │
│          │                  ├─service
│          │                  │  │  MenuPermissionService.java
│          │                  │  │  MenuService.java
│          │                  │  │  RoleMenuService.java
│          │                  │  │  RoleService.java
│          │                  │  │  UserRoleService.java
│          │                  │  │
│          │                  │  └─impl
│          │                  │          MenuPermissionServiceImpl.java
│          │                  │          MenuServiceImpl.java
│          │                  │          RoleMenuServiceImpl.java
│          │                  │          RoleServiceImpl.java
│          │                  │          UserRoleFeignController.java
│          │                  │          UserRoleServiceImpl.java
│          │                  │
│          │                  └─vo
│          │                          MenuPermissionSimpleVO.java
│          │                          MenuPermissionVO.java
│          │                          MenuSimpleVO.java
│          │                          MenuVO.java
│          │                          RoleVO.java
│          │                          RouteMetaVO.java
│          │                          RouteVO.java
│          │
│          └─resources
│              │  bootstrap.yml
│              │
│              └─mapper
│                      MenuMapper.xml
│                      MenuPermissionMapper.xml
│                      RoleMapper.xml
│                      RoleMenuMapper.xml
│                      UserRoleMapper.xml
│
├─mall4cloud-search
│  │  pom.xml
│  │
│  └─src
│      └─main
│          ├─java
│          │  └─com
│          │      └─mall4j
│          │          └─cloud
│          │              └─search
│          │                  │  SearchApplication.java
│          │                  │
│          │                  ├─bo
│          │                  │      BrandBO.java
│          │                  │      CategoryBO.java
│          │                  │      OrderBO.java
│          │                  │      ShopDetailBO.java
│          │                  │      SpuBO.java
│          │                  │      SpuExtensionBO.java
│          │                  │
│          │                  ├─canal
│          │                  │      Mall4cloudCanalBinLogEventParser.java
│          │                  │      Mall4cloudCanalBinlogEventProcessorFactory.java
│          │                  │      Mall4cloudCanalGlue.java
│          │                  │
│          │                  ├─config
│          │                  │      CanalGlueAutoConfiguration.java
│          │                  │      ElasticConfig.java
│          │                  │
│          │                  ├─constant
│          │                  │      DataType.java
│          │                  │      EsConstant.java
│          │                  │      EsIndexEnum.java
│          │                  │      EsProductSortEnum.java
│          │                  │      SearchTypeEnum.java
│          │                  │
│          │                  ├─controller
│          │                  │  ├─app
│          │                  │  │      ProductSearchController.java
│          │                  │  │
│          │                  │  ├─multishop
│          │                  │  │      ProductSearchController.java
│          │                  │  │
│          │                  │  └─platform
│          │                  │          ProductSearchController.java
│          │                  │
│          │                  ├─feign
│          │                  │      SearchOrderFeignController.java
│          │                  │      SearchSpuFeignController.java
│          │                  │
│          │                  ├─listener
│          │                  │      BrandCanalListener.java
│          │                  │      CanalListener.java
│          │                  │      CategoryCanalListener.java
│          │                  │      OrderCanalListener.java
│          │                  │      ShopDetailCanalListener.java
│          │                  │      SpuCanalListener.java
│          │                  │      SpuExtensionCanalListener.java
│          │                  │
│          │                  ├─manager
│          │                  │      OrderSearchManager.java
│          │                  │      ProductSearchManager.java
│          │                  │      ProductUpdateManager.java
│          │                  │
│          │                  └─vo
│          │                          SpuAdminVO.java
│          │
│          └─resources
│                  bootstrap.yml
│
└─mall4cloud-user
    │  pom.xml
    │
    └─src
        └─main
           ├─java
           │  └─com
           │      └─mall4j
           │          └─cloud
           │              └─user
           │                  │  UserApplication.java
           │                  │
           │                  ├─controller
           │                  │  ├─app
           │                  │  │      AreaController.java
           │                  │  │      UserAddrController.java
           │                  │  │      UserController.java
           │                  │  │      UserRegisterController.java
           │                  │  │
           │                  │  └─multishop
           │                  │          UserController.java
           │                  │
           │                  ├─dto
           │                  │      UserAddrDTO.java
           │                  │      UserDTO.java
           │                  │      UserRegisterDTO.java
           │                  │
           │                  ├─feign
           │                  │      UserAddrFeignController.java
           │                  │      UserFeignController.java
           │                  │
           │                  ├─mapper
           │                  │      AreaMapper.java
           │                  │      UserAddrMapper.java
           │                  │      UserMapper.java
           │                  │
           │                  ├─model
           │                  │      Area.java
           │                  │      User.java
           │                  │      UserAddr.java
           │                  │
           │                  ├─service
           │                  │  │  AreaService.java
           │                  │  │  UserAddrService.java
           │                  │  │  UserService.java
           │                  │  │
           │                  │  └─impl
           │                  │          AreaServiceImpl.java
           │                  │          UserAddrServiceImpl.java
           │                  │          UserServiceImpl.java
           │                  │
           │                  └─vo
           │                          UserSimpleInfoVO.java
           │                          UserVO.java
           │
           └─resources
               │  bootstrap.yml
               │
               └─mapper
                       AreaMapper.xml
                       UserAddrMapper.xml
                       UserMapper.xml

#### 目录框架

```
mall4cloud
│ 
├─db 存储与数据库相关的文件
│
├─doc 项目的文档目录，包括用户手册、设计文档、API 文档、架构图等。
│
├─es 与 Elasticsearch 相关的配置，包含搜索引擎的配置文件、数据处理逻辑等。
│
├─front-end 前端代码目录，包含 HTML、CSS、JavaScript 文件，以及前端框架的相关代码。
│
├─mall4cloud-api 内网接口
│  ├─mall4cloud-api-auth  授权对内接口
│  ├─mall4cloud-api-biz  biz对内接口
│  ├─mall4cloud-api-leaf  美团分布式id生成接口
│  ├─mall4cloud-api-multishop  店铺对内接口
│  ├─mall4cloud-api-order  订单对内接口
│  ├─mall4cloud-api-platform  平台对内接口
│  ├─mall4cloud-api-product  商品对内接口
│  ├─mall4cloud-api-rbac  用户角色权限对内接口
│  ├─mall4cloud-api-search  搜索对内接口
│  └─mall4cloud-api-user  用户对内接口
│
├─mall4cloud-auth  授权校验模块
│
├─mall4cloud-biz  mall4cloud 业务代码。如图片上传/短信等
│
├─mall4cloud-common  一些公共的方法
│  ├─mall4cloud-common-cache  缓存相关公共代码
│  ├─mall4cloud-common-core  公共模块核心（公共中的公共代码）
│  ├─mall4cloud-common-database  数据库连接相关公共代码
│  ├─mall4cloud-common-order  订单相关公共代码
│  ├─mall4cloud-common-rocketmq  rocketmq相关公共代码
│  └─mall4cloud-common-security  安全相关公共代码
│
├─mall4cloud-gateway  网关
│
├─mall4cloud-leaf  基于美团leaf的生成id服务
│
├─mall4cloud-multishop  商家端
│
├─mall4cloud-order  订单服务
│
├─mall4cloud-payment  支付服务
│
├─mall4cloud-platform  平台端
│
├─mall4cloud-product  商品服务
│
├─mall4cloud-rbac  用户角色权限模块
│
├─mall4cloud-search  搜索模块
│
└─mall4cloud-user  用户服务
```

#### mall4cloud-auth模块目录结构

```
mall4cloud-auth
   └─src
       └─main
           └─java
              └─com
                  └─mall4j
                      └─cloud
                          └─auth
                              │  AuthApplication.java
                              │
                              ├─adapter
                              │      CaptchaCacheServiceRedisImpl.java
                              │
                              ├─config
                              │      CaptchaConfig.java
                              │
                              ├─constant
                              │      AuthAccountStatusEnum.java
                              │
                              ├─controller
                              │      CaptchaController.java
                              │      LoginController.java
                              │      PasswordController.java
                              │      TokenController.java
                              │
                              ├─dto
                              │      AuthenticationDTO.java
                              │      CaptchaAuthenticationDTO.java
                              │      RefreshTokenDTO.java
                              │      UpdatePasswordDTO.java
                              │
                              ├─feign
                              │      AccountFeignController.java
                              │      TokenFeignController.java
                              │
                              ├─manager
                              │      TokenStore.java
                              │
                              ├─mapper
                              │      AuthAccountMapper.java
                              │
                              ├─model
                              │      AuthAccount.java
                              │
                              └─service
                                  │  AuthAccountService.java
                                  │
                                  └─impl
                                          AuthAccountServiceImpl.java
            
```

